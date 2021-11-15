import os

root = 'D:\\Projects\\uploads\\2021'

for d in os.listdir(root):
    path = root + '\\' + d
    file_list = os.listdir(path)
    for file_name in file_list:
        old_name = path + '\\' + file_name
        suffix = file_name.split('.')[-1]
        name = file_name.rsplit('_', 2)[0]

        new_name = path + '\\' + name + '.' + suffix

        os.rename(old_name, new_name)
