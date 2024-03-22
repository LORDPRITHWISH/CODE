import os

LOC = r'C:\Users\prith\Desktop\YOUDOWN\TOC GS'

# Iterate through contents of the directory
for filename in os.listdir(LOC):
    # Construct the full path to the file
    filepath = os.path.join(LOC, filename)
    
    # Check if the path corresponds to a file
    if os.path.isfile(filepath):
        # Extract the new filename by removing the last character
        new_filename = filename[:-1]
        
        # Construct the full path to the new filename
        new_filepath = os.path.join(LOC, new_filename)
        
        # Rename the file
        os.rename(filepath, new_filepath)
        # print(f"Renamed '{filename}' to '{new_filename.encode('utf-8', 'ignore').decode('utf-8')}'")
