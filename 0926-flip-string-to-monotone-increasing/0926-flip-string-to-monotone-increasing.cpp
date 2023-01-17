// Approach
// When We are traversing in the string S there will be two possibility

// Char=='1'
// It will not impact our minimum flips just keep the record of count of 1
// Char=='0'
// Here will be 2 cases
// Keep is as 0 and flip all the 1 so far ,for that we need to know about the count the one so far
// Flip it to 1 and update our count_flip
// Take the minmum of count_flip and count_one and update the count_flip because we want minimum(dry run for 1110000)
// Example: string S= 00110
// after 1st iteration : count_one = 0,count_flip = 1,
// count_flip=min(1,0)=0;
// after 2nd iteration : count_one = 0,count_flip = 1,
// count_flip=min(1,0)=0;
// after 3rd iteration : count_one = 1,count_flip = 0,
// after 4th iteration : count_one = 2,count_flip = 0,
// after 5th iteration : count_one = 2,count_flip = 1,
// count_flip=min(2,1)=1;
// it will return 1 as answer

// Try to dry run with string S=010110 and string S=111100000

// Complexity
// Time complexity:- O(N)
// Space complexity:- O(1)
class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int count_flip = 0, count_one = 0;
        for (auto i : S)
        { 
 //keep track of all one (we will use count_one in else condition if we need)  
//if we want flip one into 0
            if (i == '1')
                count_one++;
            else{
                count_flip++;
            count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};