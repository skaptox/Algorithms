=begin

Exercise: Write a function to count the number of bits
that are different between two numbers

https://www.youtube.com/watch?v=7jkIUgLC29I

=end


require 'benchmark'

def bits_different(number_1,number_2)
    number = number_1 ^ number_2
    count = 0
    while number > 0
        number &= (number-1)
        count += 1
    end
    return count
end


arr = Array.new(1000000) {rand(0..1000000)}
arr_2 = Array.new(1000000) {rand(0..1000000)}

puts Benchmark.measure { arr.each_index {|i| bits_different(arr[i],arr_2[i])}}