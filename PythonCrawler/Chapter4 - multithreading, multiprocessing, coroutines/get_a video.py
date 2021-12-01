# normally the video is sliced and stored as many "clips"
# the order and address of the slices are stored in a M3U8 file, which is an utf-8 encoded M3U file
# in the M3U8 file, the uri for the slices lead to .ts files or the video slice directly,
#   and there could also be recoded encryption methods, keys and other info regarding the video
# thus, to get a video, we first need to find the M3U8 file, get the slices,
#   then integrate the .ts files (slices) into a whole mp4
import requests, re
#
expression = re.compile(r"url: '(?P<url>.*?)',", re.S)      # get the url of m3u8 file

url = 'https://91kanju.com/vod-play/54812-1-1.html'

res = requests.get(url)

m3u8_url = expression.search(res.text).group('url')

# print(m3u8_url)

m3u8 = requests.get(m3u8_url)
with open('.\\video.m3u8', 'wb') as fp:
    fp.write(m3u8.content)
n = 1
with open('.\\video.m3u8', 'r', encoding='utf-8') as f:
    for line in f:
        line = line.strip()
        if line.startswith('#'):
            continue

        video_clip = requests.get(line)
        f = open(f'.\\video\\{n}.ts', 'wb')
        f.write(video_clip.content)
        f.close()
        video_clip.close()
        print(f'{n} is done')
        n += 1

# to integrate the ts files, run this in cmd: copy /b *.ts [filename after integration].ts


