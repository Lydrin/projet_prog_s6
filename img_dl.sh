
str=$1
if [ ! -f ./pics/${str}_8.bmp ];then
	wget -e use_proxy=yes -e http_proxy=proxy.polytech-lille.fr:3128 -P ./pics/ http://www.tate.org.uk/art/images/work/${str:0:1}/${str:0:3}/${str}_8.jpg
	if [ -f ./pics/${str}_8.jpg ];then
		mogrify -format bmp pics/${str}_8.jpg
		rm pics/${str}_8.jpg
	fi
fi

