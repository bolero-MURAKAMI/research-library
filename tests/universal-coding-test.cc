// Copyright 2015 pixie.grasper

#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include "../includes/universal-coding.h"

int main() {
  std::vector<int> buffer(10000);
  unsigned int seed = 10;
  for (size_t i = 0; i < buffer.size(); i++) {
    buffer[i] = rand_r(&seed) % 100 + 1;
  }

  auto&& uc = ResearchLibrary::UniversalCoding::UnaryCodingEncode(buffer);
  auto&& iuc = ResearchLibrary::UniversalCoding::UnaryCodingDecode(uc);
  for (size_t i = 0; i < buffer.size(); i++) {
    if (iuc[i] != buffer[i]) {
      return 1;
    }
  }

  auto&& gamma = ResearchLibrary::UniversalCoding::GammaCodingEncode(buffer);
  auto&& igamma = ResearchLibrary::UniversalCoding::GammaCodingDecode(gamma);
  for (size_t i = 0; i < buffer.size(); i++) {
    if (igamma[i] != buffer[i]) {
      return 1;
    }
  }

  auto&& delta = ResearchLibrary::UniversalCoding::DeltaCodingEncoder(buffer);
  auto&& idelta = ResearchLibrary::UniversalCoding::DeltaCodingDecoder(delta);
  for (size_t i = 0; i < buffer.size(); i++) {
    if (idelta[i] != buffer[i]) {
      return 1;
    }
  }

  auto&& omega = ResearchLibrary::UniversalCoding::OmegaCodingEncoder(buffer);
  auto&& iomega = ResearchLibrary::UniversalCoding::OmegaCodingDecoder(omega);
  for (size_t i = 0; i < buffer.size(); i++) {
    if (iomega[i] != buffer[i]) {
      return 1;
    }
  }

  auto&& golomb = ResearchLibrary::UniversalCoding
                                 ::GolombCodingEncoder(buffer, 6);
  auto&& igolomb = ResearchLibrary::UniversalCoding
                                  ::GolombCodingDecoder(golomb, 6);
  for (size_t i = 0; i < buffer.size(); i++) {
    if (igolomb[i] != buffer[i]) {
      return 1;
    }
  }

  return 0;
}
