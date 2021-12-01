# this is a POST request, but the params are encrypted.
# check the js call stack in browser's Dev Tool and find out the place and way the params a encrypted
# using break points to see the change in variables and arguments
# for this one, params => encText, enSecKey => encSecKey in the function window.arsea(...)
from Crypto.Cipher import AES
from base64 import b64encode
import requests
import json

url = 'https://music.163.com/weapi/comment/resource/comments/get?csrf_token='

data = {  # copies from js breakpoint
    'csrf_token': "",
    'cursor': "-1",
    'offset': "0",
    'orderType': "1",
    'pageNo': "1",
    'pageSize': "20",
    'rid': "R_SO_4_1325905146",
    'threadId': "R_SO_4_1325905146"
}

e = '010001'
f = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7 '
g = '0CoJUm6Qyw8W8jud'
i = "HGQtjYCwyR9tvqmN"  # copied from browser

# the functions defined below are to simulate the encryption process of music.163.com when requests music comments
def to_16(data):
    pad = 16 - len(data) % 16
    data += chr(pad) * pad
    return data

def get_encSecKey():  # the cecKey according to the i value
    return "7eb9bbd64b9ec70cba516d70c92d65e6972165811b2aa66213bdd597cb0d10d2c68e50f18289c56cc2abc263f436ce2da39915261644148bf870441c7ae3e2a823febc932e927e85599de69abf1d0f406a362742564ae087cbb3a6fd532511e495f17e1e4637bb1c1bfb4820adca00daaa5f81506ce2ef3267be3ba61a4572cc"


def get_params(data):  # simulate encryption process of data (function d below)
    first_encryption = enc_params(data, g)
    second_encryption = enc_params(first_encryption, i)
    return second_encryption


def enc_params(data, key):
    iv = '0102030405060708'
    data = to_16(data)
    aes = AES.new(key=key.encode('utf-8'), IV=iv.encode('utf-8'), mode=AES.MODE_CBC)
    bs = aes.encrypt(data.encode('utf-8'))
    return str(b64encode(bs), 'utf-8')


res = requests.post(url, data={
    'params': get_params(json.dumps(data)),
    'encSecKey': get_encSecKey()
})

print(res.text)

# encrypt functions found, used to reappear the encryption process
"""     
function a(a) {
        var d, e, b = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", c = "";
        for (d = 0; a > d; d += 1)   # loop 16 times
            e = Math.random() * b.length,   # random number
            e = Math.floor(e),  # integer
            c += b.charAt(e);   # insert b[e] into c
        return c    # random 16 characters 
    }
    function b(a, b) {
        var c = CryptoJS.enc.Utf8.parse(b)  # b is the key
          , d = CryptoJS.enc.Utf8.parse("0102030405060708")
          , e = CryptoJS.enc.Utf8.parse(a)  # e is the data
          , f = CryptoJS.AES.encrypt(e, c, {    # c has to be the key
            iv: d,
            mode: CryptoJS.mode.CBC
        });
        return f.toString()
    }
    function c(a, b, c) {
        var d, e;
        return setMaxDigits(131),
        d = new RSAKeyPair(b,"",c),
        e = encryptedString(d, a)
    }
    function d(d, e, f, g) { # d: data, e: 010001, f: a long string, g: 0CoJUm6Qyw8W8jud
        var h = {}
          , i = a(16);  # 16 characters random string
        return h.encText = b(d, g),     # g is key
        h.encText = b(h.encText, i),    # encText is the params we need, after 2 times encryption, i is key
        h.encSecKey = c(i, e, f),       # since c doesn't generate random characters and e, f are constants, the output depands only on i
        h
    }
"""
