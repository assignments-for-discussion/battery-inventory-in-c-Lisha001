#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int l=0.med=0,high=0;
  for(i=0;i<nBatteries;i++){
    if(chargeCycleCounts[i]<310)
    {
    l=l++;
    }
    else if(chargeCycleCounts[i]>=310 && chargerCycleCounts[i]<=929)
      med=med++;
    else{
    high=high++;}
      
    }
  counts={l,med,high};
 
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
