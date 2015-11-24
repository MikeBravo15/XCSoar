from build.project import Project
from build.zlib import ZlibProject
from build.autotools import AutotoolsProject
from build.freetype import FreeTypeProject
from build.lua import LuaProject

zlib = ZlibProject(
    'http://zlib.net/zlib-1.2.8.tar.xz',
    '28f1205d8dd2001f26fec1e8c2cebe37',
    'lib/libz.a',
)

freetype = FreeTypeProject(
    'http://download.savannah.gnu.org/releases/freetype/freetype-2.6.1.tar.bz2',
    '35cb8f4d9e5906847901bb39324c2f80',
    'lib/libfreetype.a',
    [
        '--disable-shared', '--enable-static',
        '--without-bzip2', '--without-png',
        '--without-harfbuzz',
    ],
)

curl = AutotoolsProject(
    'http://curl.haxx.se/download/curl-7.45.0.tar.lzma',
    'c9a0a77f71fdc6b0f925bc3e79eb77f6',
    'lib/libcurl.a',
    [
        '--disable-shared', '--enable-static',
        '--disable-debug',
        '--enable-http',
        '--enable-ipv6',
        '--disable-ftp', '--disable-file',
        '--disable-ldap', '--disable-ldaps',
        '--disable-rtsp', '--disable-proxy', '--disable-dict', '--disable-telnet',
        '--disable-tftp', '--disable-pop3', '--disable-imap', '--disable-smb',
        '--disable-smtp',
        '--disable-gopher',
        '--disable-manual',
        '--disable-threaded-resolver', '--disable-verbose', '--disable-sspi',
        '--disable-crypto-auth', '--disable-ntlm-wb', '--disable-tls-srp', '--disable-cookies',
        '--without-ssl', '--without-gnutls', '--without-nss', '--without-libssh2',
    ],
    use_clang=True,
)

libpng = AutotoolsProject(
    'ftp://ftp.simplesystems.org/pub/libpng/png/src/libpng16/libpng-1.6.19.tar.xz',
    '1e6a458429e850fc93c1f3b6dc00a48f',
    'lib/libpng.a',
    [
        '--disable-shared', '--enable-static',
        '--enable-arm-neon',
    ]
)

libjpeg = AutotoolsProject(
    'http://downloads.sourceforge.net/project/libjpeg-turbo/1.4.2/libjpeg-turbo-1.4.2.tar.gz',
    '86b0d5f7507c2e6c21c00219162c3c44',
    'lib/libjpeg.a',
    [
        '--disable-shared', '--enable-static',
    ]
)

lua = LuaProject(
    'http://www.lua.org/ftp/lua-5.3.1.tar.gz',
    '797adacada8d85761c079390ff1d9961',
    'lib/liblua.a',
)