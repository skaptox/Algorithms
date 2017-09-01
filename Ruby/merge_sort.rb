=begin
Copyright (c) 2017 Oscar Albornoz. All rights reserved.
=end

def merge_sort(array)
    return array if array.length() < 2
    middle = array.length() >> 1
    array_1 = merge_sort(array[0...middle])
    array_2 = merge_sort(array[middle..-1])
    merge(array_1,array_2)
end

def merge(array_1,array_2)
    array = []
    i = j = 0
    while i < array_1.length() and j < array_2.length()
        if array_1[i] < array_2[j]
            array.push(array_1[i])
            i += 1
        else
            array.push(array_2[j])
            j += 1
        end
    end
    array.concat(array_1[i..-1])
    array.concat(array_2[j..-1])
end

array =Array.new(10) { rand(-9..9) }
puts "Before"
print array
puts "\nAfter"
print merge_sort(array)
puts

