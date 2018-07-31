import os, re
import shutil

time_limit = 1
memory_limit = 131072

f_list = os.listdir(r'data')
f_config_file = open('Config.ini', 'w')
try :
    os.mkdir('Input')
    # print 'Made menu "Input" successfully.'
except WindowsError:
    # print 'Menu "Input" has been maked.'
    pass
try :
    os.mkdir('Output')
    # print 'Made menu "Output" successfully.'
except WindowsError:
    # print 'Menu "Output" has been maked.'
    pass

f_check = []
f_config = ''
f_count = 0

for f_name in f_list :
    try :
        f_title = re.split(r'\.', f_name)[0]
        if (f_title + '.in') in f_list \
                and (f_title + '.out') in f_list \
                and not f_title in f_check :
            f_check.append(f_title)
            f_count += 1
            f_in_name = f_title + '.in'
            f_out_name = f_title + '.out'
            shutil.copy('data/' + f_in_name, 'Input')
            shutil.copy('data/' + f_out_name, 'Output')
        # print 'Opened and copied file "%s" successfully.' % f_name
    except :
        # print 'File "%s" could not be opened or copied.' % f_name
        pass

try :
    for f_i in range(0, len(f_check)) :
        f_title = f_check[f_i]
        f_in_name = f_title + '.in'
        f_out_name = f_title + '.out'
        f_point = 100 // f_count
        if f_i >= (f_count - 100 % f_point) : 
            f_point += 1
        f_config += '%s|%s|%s|%s|%s\n' % (f_in_name, f_out_name, time_limit, str(f_point), memory_limit)

    f_config = str(f_count) + '\n' + f_config
    #for f_i in range(0, f_count):
        #f_config = f_config % '1'
    f_config_file.write(f_config)
    f_config_file.close()
    # print 'Generated file "Config.ini" successfully'
except :
    # print 'File "Config.ini" could not be opened or copied.'
    pass
    
# print 'Finished.'
