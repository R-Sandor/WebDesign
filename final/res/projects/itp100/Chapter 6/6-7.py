#This program saves a sequence of video running times
#to the video_times.txt file.

def main():
    # Get the number of videos running times
    numvideos = int(input('How many videos are in the project? '))
    
    #Open the file to hold the running times
    video_file = open('videotimes.txt' , 'w')

    #Get each video's running time and write
    #it to the file
    print('Enter the running times for each video')
    for count in range(1, numvideos + 1):
        run_time = float(input('video #' + str(count) + ': '))
        video_file.write =(str(run_time) + '\n')

    #close the file.
        video_file.close()
        print('The times have been saved to video_times.txt.')
#Call the main function
main()
