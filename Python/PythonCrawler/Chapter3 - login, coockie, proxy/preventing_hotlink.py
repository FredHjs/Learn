import requests

# choose a video link from pearvideo.com
url = 'https://www.pearvideo.com/video_1735018'
cont_id = url.split("_")[-1]
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 ',
    # refer : source of the request, which is the preventing hotlink.
    # it is limited the the requests have to come from the url, not unknown source (crawler)
    'Referer': url
}
# find the data package that contains the video src
video_status_url = f'https://www.pearvideo.com/videoStatus.jsp?contId={cont_id}&mrd=0.734359175897392'

res = requests.get(video_status_url, headers=headers)

video_status_dic = res.json()

# in the json returned, find the video src. But this is the wrong link with time stamp
# src from the json : https://video.pearvideo.com/mp4/third/20210713/1626207955899-15195380-162244-hd.mp4
# actual video link : https://video.pearvideo.com/mp4/third/20210713/cont-1735018-15195380-162244-hd.mp4
video_src = video_status_dic['videoInfo']['videos']['srcUrl']
system_time = video_status_dic['systemTime']  # time stamp used in video_src

# to form the actual video src, replace the time stamp with contId
video_src = video_src.replace(system_time, 'cont-' + cont_id)

# download video
with open('.\\pearvideo.mp4', 'wb') as fp:
    fp.write(requests.get(video_src).content)
print('done.')