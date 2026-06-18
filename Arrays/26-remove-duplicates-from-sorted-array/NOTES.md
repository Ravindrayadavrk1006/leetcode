​
/**** SOLUTION ONE******/
/***idea=>javascript solution=> we are trying from last if our seen object has seen that element the current element then we remove that element from original array using splice else we keep moving back ******/
 const seen = {}
    let count = nums.length
    while(true){
        if(count < 0) break
        if(seen[nums[count]]){
            nums.splice(count, 1);  
        } else {
            seen[nums[count]] = true
        }
        count--
    }
