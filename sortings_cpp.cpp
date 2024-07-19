#include <iostream>
#include <vector>
using namespace std;

class vector_getter_setter{
    public:
    void get_vector(vector<int> &nums){
        int num_length;
        cout << "Enter Length : ";
        cin >> num_length;
        cout << endl;

        for(int i=0; i<num_length; i++){
            int num;
            cout << "Enter Number : ";
            cin >> num;
            nums.push_back(num);
        }
    }
    
    void print_vector(vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << endl;
        }
        cout<<endl;
    }
};

class basic_sortings : 
public vector_getter_setter{
    public:
    void swap(int &a, int &b){
        int temp = b;
        b = a;
        a = temp;
    }

    void selection_sort(vector<int> &nums){
        // We select minimums
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
        // Bring min on the 0th index, 
        // swap with what we have on the 
        // 0th index Then we see in the 
        // remaining array.
        
        cout<<endl<<"Selection Sort"<<endl;
        int min;
        int nums_length = nums.size();
        
        for(int i=0; i<=nums_length-2; i++){
            min = i;
            
            for(int j=i; j<=nums_length-1; j++){
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }

    void bubble_sort(vector<int> &nums){
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
        // We compare the 0th index with
        // the 1st index and swap if 0th
        // index is greater than 1st index
        
        cout<<endl<<"Bubble Sort"<<endl;
        int nums_length = nums.size();
        for(int i=0; i<nums_length-1; i++){
            for(int j=i+1; j<nums_length; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
    }

    void insertion_sort(vector<int> &nums){
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
        // It takes an element and places
        // the element in its correct
        // position in the array. We see left
        
        int nums_length = nums.size();
        for(int i=0; i<=nums_length-1; i++){
            int j = i;
            
            while(j>0 && nums[j-1] > nums[j]){
                swap(nums[j-1], nums[j]);
                j--;
            }
        }
    }
};

class adavance_sortings :  
public vector_getter_setter{
    public:
    int pivot_counter(vector<int> &nums, int low, int high){
        int pivot = nums[low];      // We store the first element
        int i = low;                // Holds index 0  
        int j = high;               // Holds index 4

        while(i<j){
            while(nums[i] <= pivot && i<=high-1){
                i++;    // Till the time value at index 'i' is less than pivot, i++
            }

            while(nums[j]>pivot && j>=low+1){
                j--;
            }

            if(i<j){
                swap(nums[i], nums[j]);
            }
        }   

        swap(nums[low], nums[j]);       // End we swap j, and pivot
        return j;
    }

    void quick_sort(vector<int> &nums, int low, int high){
        // Time Complexity : O(nlogn)
        // Space Complexity : O(logn)
        // We take the first element as
        // the pivot and then we partition
        // the array around the pivot
        // Them place it in its correct
        // position in the array.

        if(low<high){
            int pivot = pivot_counter(nums, low, high);
            quick_sort(nums, low, pivot-1);
            quick_sort(nums, pivot+1, high);
        }
    }

    void merge_array(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;

        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }

            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while (right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }
    
    void merge_sort(vector<int> &nums, int low, int high){
        // Divide and merge
        // Time Complexity : O(nlogn)
        // Space Complexity : O(n)
        // We divide the array into two
        // parts and then merge them

        if(low == high){
            return;
        }

        int mid = (low+high)/2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid+1, high);
        merge_array(nums, low, mid, high);
    }
};

int main(){
    vector<int> nums;

    basic_sortings obj_sortings;
    obj_sortings.get_vector(nums);
    obj_sortings.selection_sort(nums);
    obj_sortings.bubble_sort(nums);
    obj_sortings.insertion_sort(nums);
    
    obj_sortings.print_vector(nums);
    
    adavance_sortings obj_advance;
    obj_advance.quick_sort(nums, 0, nums.size()-1);
    obj_advance.merge_sort(nums, 0, nums.size()-1);
    
    obj_advance.print_vector(nums);

    return 0;
}