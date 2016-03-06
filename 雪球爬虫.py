#coding=utf-8
__author__ = 'Administrator'

import requests
from lxml import etree
import json
import re
import sys
sys.path.append("../")
import jieba
jieba.load_userdict("ihufa.txt")
import xlwt
import xlrd

headers = {'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_3) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.54 Safari/536.5'}
url0 = 'http://club.jr.jd.com/jijin/jingxuan&pageNo=2'
goodscount = 0
hufa = xlwt.Workbook()
#新建工作表
data = hufa.add_sheet("hufa_data")
data.write(0,0,"No.")
data.write(0,1,"Title")
data.write(0,2,"id")
data.write(0,3,"Price")
data.write(0,4,"Commits")
brand = hufa.add_sheet("brand")
brand.write(0,0,"No.")
brand.write(0,1,"Title")
brand.write(0,2,"Brand")
brand.write(0,3,"page")
brand.write(0,4,"Count")
fenci = hufa.add_sheet("fenci")
fenci.write(0,0,"No.")
fenci.write(0,1,"Title")
fenci.write(0,2,"WordSeg")
txt = open(r'hufabrand.txt','r').read()
txt = txt.decode("gbk")
brandlist = txt.split()

for page in range(1,5):
    url = url0 + str(page)
    html = requests.get(url,headers=headers).text
    selector = etree.HTML(html)
    id = selector.xpath('//div[@is_parallel_stock="0"]/@data-sku')
    title = selector.xpath('//div[@is_parallel_stock="0"]/div[@class="p-name"]/a/em/text()')
    commit = selector.xpath('//div[@is_parallel_stock="0"]/div[@class="p-commit"]/strong/a/text()')
    # 得累加每一页的商品数，否则会出现重写的情况
    for i in range(0,len(id)):

        #得到商品价格
#        price_html=requests.get("http://p.3.cn/prices/mgets?&callback=jQuery53235&my=list_price&type=1&area=1_72_4137&skuIds=J_"+str(id[i]),headers=headers).text
#        price = re.findall('p":"(.*?)","m',price_html)
        # print "id:",id[i]
        # print "title:",title[i]
        # print "commit:",commit[i]
        # print float(price[0])
        # print price
        #打印商品数据在"data"工作表中
        #print basic info of goods
        data.write(i+goodscount+1,0,i+goodscount+1)
        data.write(i+goodscount+1,2,id[i])
        data.write(i+goodscount+1,1,title[i])
 #       data.write(i+goodscount+1,3,float(price[0]))
        data.write(i+goodscount+1,4,commit[i])

        #分词并且写入分词结果
        a = list(jieba.cut(title[i]))
        fenci.write(i+goodscount+1,0,i+goodscount+1)
        brand.write(i+goodscount+1,0,i+goodscount+1)
        brand.write(i+goodscount+1,1,title[i])
        for w in range(0,len(a)):
            fenci.write(i+goodscount+1,w+1,a[w])
        brandnotfound = 1

        #开始循环标题下的每个分词
        for k in range(0,len(a)):
            #循环品牌列表
            for l in range(0,len(brandlist)):
                #识别品牌
                if brandlist[l]==a[k]:
                    brand.write(i+goodscount+1,2,brandlist[l])
                    brand.write(i+goodscount+1,3,page)
                    brand.write(i+goodscount+1,4,"1")
                    brandnotfound = 0
                    break
            if brandnotfound == 0:
                break

        if brandnotfound:
            print i
 #           print title[i]
            for pw in list(jieba.cut(title[i])):
                print pw
            print "////////////////////////////////////////"

            brand.write(i+goodscount+1,2,"error")
            brand.write(i+goodscount+1,3,page)
            brand.write(i+goodscount+1,4,"1")

    #调试节点：单循环开始
    # break
    goodscount = goodscount + len(title)
    print "page",page,"Done!"
hufa.save("hufaInfo.xls")
print "Done!"


# for each in id:
#
#     price_url = "http://p.3.cn/prices/mgets?&callback=jQuery53235&my=list_price&type=1&area=1_72_4137&skuIds=J_" + str(each)
#     price_info = requests.get(price_url,headers=headers).text
#     price = re.findall('"p":"(.*?)","m"',price_info)
#     print each
#     print price


