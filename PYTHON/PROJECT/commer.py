import os
LOC = r'C:\Users\prith\Desktop\YOUDOWN\TOC GS'

            
content = os.listdir(LOC)
for subdir in content:
    # subdir_path = os.path.join(LOC, subdir)
    # video_files = os.listdir(subdir)
    # print(subdir_path)
    # print(video_files)
    # output_filename = os.path.join(LOC, f"{subdir[0,-1]}")
    os.rename(subdir,f"{subdir[0:-1]}")
    # make(video_files,output_filename)