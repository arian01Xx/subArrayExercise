#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class SolutionTwenyOne{
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int totalSum=0;
        int n=nums.size();

        for(int i=0; i<n; i++) totalSum+=nums[i];

        if(totalSum%p==0) return 0;

        long long int targetRemainder=totalSum%p; //el valor que queremos eliminar, el resto
        int cnt=n;
        long long int currentSum=0;
        unordered_map<int,int> remainderIndexMap;
        remainderIndexMap[0]= -1;

        for(int i=0; i<n; i++){
            currentSum=(currentSum+nums[i])%p; //da el resto que llevariamos si se toma todos los numeros hasta i
            int desiredRemainder=(currentSum-targetRemainder+p)%p; //el resto adecuado para eliminar el subarreglo que epermita que la nueva suma sea divisible por p
            if(remainderIndexMap.find(desiredRemainder) != remainderIndexMap.end()){ //si encontramos, existe un subarreglo cuya eliminación logra el objetivo
                cnt=min(cnt, i-remainderIndexMap[desiredRemainder]);
            }
            remainderIndexMap[currentSum]=i;
        }
        return cnt < n ? cnt:-1;
    }
};

int main(){
	return 0;
}