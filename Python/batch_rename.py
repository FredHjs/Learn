import os

path = 'D:\\Projects\\uploads\\2020\\06'

file_list = os.listdir(path)

for file_name in file_list:
    old_name = path + '\\' + file_name
    suffix = file_name.split('.')[-1]
    name = file_name.rsplit('_', 3)[0]

    new_name = path + '\\' + name + '.' + suffix

    os.rename(old_name, new_name)
