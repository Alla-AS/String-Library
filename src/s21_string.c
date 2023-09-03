#include "s21_string.h"

void *s21_memchr(const void *str, int c, S21_SIZE_T n) {
    const char *tmp = (const char*) str;
    unsigned char chr = (unsigned char) c;
    char *buf = S21_NULL;

    for (S21_SIZE_T i = 0; i < n; i++) {
        if (tmp[i] == chr) {
            buf = (void *)(&tmp[i]);
            break;
        }
    }
    return buf;
}

int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n) {
    int res = 0;
    for (S21_SIZE_T i = 0; i < n && !res; i++) {
        if (*((char *)str1 + i) != *((char *)str2 + i))
            res = *((char *)str1 + i) - *((char *)str2 + i);
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, S21_SIZE_T n) {
    const char *src_new = (const char*)src;
    char *dest_new = (char*)dest;
    for (S21_SIZE_T i = 0; i < n; src_new++, dest_new++, i++) {
        *dest_new = *src_new;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, S21_SIZE_T n) {
    char* chdest = dest;
    const char* chsrc = src;
    if (chdest <= chsrc || chdest >= chsrc + n) {
        while (n--)
            *chdest++ = *chsrc++;
    } else {
        chdest = chdest + n - 1;
        chsrc = chsrc + n - 1;
        while (n--)
            *chdest-- = *chsrc--;
    }
    return dest;
}

void *s21_memset(void *str, int c, S21_SIZE_T n) {
    unsigned char chr = (unsigned char)c;
    char *tmp = str;
    for (S21_SIZE_T i = 0; i < n; i++) {
        tmp[i] = chr;
    }
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    char *tmp = dest;
    while (*tmp)
        tmp++;
    while (*src) {
        *tmp = *src;
        tmp++;
        src++;
    }
    *tmp = *src;
    return (dest);
}

char *s21_strncat(char *dest, const char *src, S21_SIZE_T n) {
    char *tmp = dest;
    while (*tmp)
        tmp++;
    for (S21_SIZE_T i = 0; i < n; i++, tmp++, src++) {
        *tmp = *src;
    }
    *tmp = '\0';
    return (dest);
}

char *s21_strchr(const char *str, int c) {
    const char *tmp = str;
    unsigned char chr = (unsigned char)c;
    while (*tmp) {
        if (*tmp == chr)
            break;
        tmp++;
    }
    if (*tmp == '\0' && c != 0) {
        tmp = S21_NULL;
    }
    return ((char *) tmp);
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int s21_strncmp(const char *str1, const char *str2, S21_SIZE_T n) {
    for (S21_SIZE_T i = 0; *str1 == *str2 && i < n - 1; i++) {
        str1++;
        str2++;
    }
    return n == 0 ? 0 : (*str1 - *str2);
}

char *s21_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while (*src) {
        *tmp = *src;
        tmp++;
        src++;
    }
    *tmp = *src;
    return (dest);
}

char *s21_strncpy(char *dest, const char *src, S21_SIZE_T n) {
    char *tmp = dest;
    for (S21_SIZE_T i = 0; i < n; i++, tmp++, src++) {
        if (*src) {
            *tmp = *src;
        } else {
            *tmp = 0;
        }
    }
    return (dest);
}

S21_SIZE_T s21_strcspn(const char *str1, const char *str2) {
    S21_SIZE_T count = 0;
    int flag = 1;
    for (; *str1; str1++) {
        if (flag) {
            count++;
            const char *tmp = str2;
            for (; *tmp; tmp++) {
                if (*str1 == *tmp) {
                    flag = 0;
                    count--;
                    break;
                }
            }
        }
    }
    return(count);
}

char *s21_strerror(int nmb) {
    static char unknown[27];
    s21_sprintf(unknown, "Unknown error: %d", nmb);
    #define ERRSTR(v, s) do {    \
        if (nmb == (v))          \
            return (s);          \
    } while (0);
    ERRSTR(0, "Undefined error: 0");
    ERRSTR(EPERM, "Operation not permitted");
    ERRSTR(ENOENT, "No such file or directory");
    ERRSTR(ESRCH, "No such process");
    ERRSTR(EINTR, "Interrupted system call");
    ERRSTR(EIO, "Input/output error");
    ERRSTR(ENXIO, "Device not configured");
    ERRSTR(E2BIG, "Argument list too long");
    ERRSTR(ENOEXEC, "Exec format error");
    ERRSTR(EBADF, "Bad file descriptor");
    ERRSTR(ECHILD, "No child processes");
    ERRSTR(EDEADLK, "Resource deadlock avoided");
    ERRSTR(ENOMEM, "Cannot allocate memory");
    ERRSTR(EACCES, "Permission denied");
    ERRSTR(EFAULT, "Bad address");
    ERRSTR(ENOTBLK, "Block device required");
    ERRSTR(EBUSY, "Resource busy");
    ERRSTR(EEXIST, "File exists");
    ERRSTR(EXDEV, "Cross-device link");
    ERRSTR(ENODEV, "Operation not supported by device");
    ERRSTR(ENOTDIR, "Not a directory");
    ERRSTR(EISDIR, "Is a directory");
    ERRSTR(EINVAL, "Invalid argument");
    ERRSTR(ENFILE, "Too many open files in system");
    ERRSTR(EMFILE, "Too many open files");
    ERRSTR(ENOTTY, "Inappropriate ioctl for device");
    ERRSTR(ETXTBSY, "Text file busy");
    ERRSTR(EFBIG, "File too large");
    ERRSTR(ENOSPC, "No space left on device");
    ERRSTR(ESPIPE, "Illegal seek");
    ERRSTR(EROFS, "Read-only file system");
    ERRSTR(EMLINK, "Too many links");
    ERRSTR(EPIPE, "Broken pipe");
    ERRSTR(EDOM, "Numerical argument out of domain");
    ERRSTR(ERANGE, "Result too large");
    ERRSTR(EAGAIN, "Resource temporarily unavailable");
    ERRSTR(EINPROGRESS, "Operation now in progress");
    ERRSTR(EALREADY, "Operation already in progress");
    ERRSTR(ENOTSOCK, "Socket operation on non-socket");
    ERRSTR(EDESTADDRREQ, "Destination address required");
    ERRSTR(EMSGSIZE, "Message too long");
    ERRSTR(EPROTOTYPE, "Protocol wrong type for socket");
    ERRSTR(ENOPROTOOPT, "Protocol not available");
    ERRSTR(EPROTONOSUPPORT, "Protocol not supported");
    ERRSTR(ESOCKTNOSUPPORT, "Socket type not supported");
    ERRSTR(EOPNOTSUPP, "Operation not supported");
    ERRSTR(EPFNOSUPPORT, "Protocol family not supported");
    ERRSTR(EAFNOSUPPORT, "Address family not supported by protocol family");
    ERRSTR(EADDRINUSE, "Address already in use");
    ERRSTR(EADDRNOTAVAIL, "Can't assign requested address");
    ERRSTR(ENETDOWN, "Network is down");
    ERRSTR(ENETUNREACH, "Network is unreachable");
    ERRSTR(ENETRESET, "Network dropped connection on reset");
    ERRSTR(ECONNABORTED, "Software caused connection abort");
    ERRSTR(ECONNRESET, "Connection reset by peer");
    ERRSTR(ENOBUFS, "No buffer space available");
    ERRSTR(EISCONN, "Socket is already connected");
    ERRSTR(ENOTCONN, "Socket is not connected");
    ERRSTR(ESHUTDOWN, "Can't send after socket shutdown");
    ERRSTR(ETOOMANYREFS, "Too many references: can't splice");
    ERRSTR(ETIMEDOUT, "Operation timed out");
    ERRSTR(ECONNREFUSED, "Connection refused");
    ERRSTR(ELOOP, "Too many levels of symbolic links");
    ERRSTR(ENAMETOOLONG, "File name too long");
    ERRSTR(EHOSTDOWN, "Host is down");
    ERRSTR(EHOSTUNREACH, "No route to host");
    ERRSTR(ENOTEMPTY, "Directory not empty");
    ERRSTR(EPROCLIM, "Too many processes");
    ERRSTR(EUSERS, "Too many users");
    ERRSTR(EDQUOT, "Disc quota exceeded");
    ERRSTR(ESTALE, "Stale NFS file handle");
    ERRSTR(EREMOTE, "Too many levels of remote in path");
    ERRSTR(EBADRPC, "RPC struct is bad");
    ERRSTR(ERPCMISMATCH, "RPC version wrong");
    ERRSTR(EPROGUNAVAIL, "RPC prog. not avail");
    ERRSTR(EPROGMISMATCH, "Program version wrong");
    ERRSTR(EPROCUNAVAIL, "Bad procedure for program");
    ERRSTR(ENOLCK, "No locks available");
    ERRSTR(ENOSYS, "Function not implemented");
    ERRSTR(EFTYPE, "Inappropriate file type or format");
    #ifdef EAUTH
        ERRSTR(EAUTH, "Authentication error");
    #endif
    #ifdef ENEEDAUTH
        ERRSTR(ENEEDAUTH, "Need authenticator");
    #endif
        ERRSTR(EIDRM, "Device power is off");
        ERRSTR(ENOMSG, "Device error");
    #ifdef EOVERFLOW
        ERRSTR(EOVERFLOW, "Value too large to be stored in data type");
    #endif
        ERRSTR(ECANCELED, "Bad executable (or shared library)");
        ERRSTR(EILSEQ, "Bad CPU type in executable");
    #ifdef ENOATTR
        ERRSTR(ENOATTR, "Shared library version mismatch");
    #endif
    #ifdef EDOOFUS
        ERRSTR(EDOOFUS, "Malformed Mach-o file");
    #endif
    #ifdef EBADMSG
        ERRSTR(EBADMSG, "Operation canceled");
    #endif
    #ifdef EMULTIHOP
        ERRSTR(EMULTIHOP, "Identifier removed");
    #endif
    #ifdef ENOLINK
        ERRSTR(ENOLINK, "No message of desired type");
    #endif
    #ifdef EPROTO
        ERRSTR(EPROTO, "Illegal byte sequence");
    #endif
    ERRSTR(93, "Attribute not found");
    ERRSTR(94, "Bad message");
    ERRSTR(95, "EMULTIHOP (Reserved)");
    ERRSTR(96, "No message available on STREAM");
    ERRSTR(97, "ENOLINK (Reserved)");
    ERRSTR(98, "No STREAM resources");
    ERRSTR(99, "Not a STREAM");
    ERRSTR(100, "Protocol error");
    ERRSTR(101, "STREAM ioctl timeout");
    ERRSTR(102, "Operation not supported on socket");
    ERRSTR(103, "Policy not found");
    ERRSTR(104, "State not recoverable");
    ERRSTR(105, "Previous owner died");
    ERRSTR(106, "Interface output queue is full");
    return unknown;
}

S21_SIZE_T s21_strlen(const char *str) {
    S21_SIZE_T lenght = 0;
    while (*str) {
        str++;
        lenght++;
    }
    return (lenght);
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *return_value = S21_NULL;
    for (; *str1; str1++) {
        if (!return_value) {
            const char *tmp = str2;
            for (; *tmp; tmp++) {
                if (*tmp == *str1) {
                    return_value = (char*)str1;
                    break;
                }
            }
        }
    }
    return return_value;
}

char *s21_strrchr(const char *str, int c) {
    char *return_value = S21_NULL;
    for (; *str; str++) {
        if (*str == c) {
            return_value = (char*) str;
        }
    }
    if (*str == 0 && c == 0)
        return_value = (char*)str;
    return (return_value);
}

S21_SIZE_T s21_strspn(const char *str1, const char *str2) {
    S21_SIZE_T lenght = 0;
    int flag = 1;
    for (; *str1; str1++) {
        if (flag) {
            const char *tmp = str2;
            for (; *tmp; tmp++) {
                if (*str1 == *tmp) {
                    lenght++;
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            }
        } else {
            break;
        }
    }
    return lenght;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *tmp_needle = (char*) needle;
    char *value_return = S21_NULL;
    if (!*needle) {
        value_return = (char *)haystack;
    } else {
        for (; *haystack; haystack++) {
            if (*haystack != *tmp_needle) {
                continue;
            }
            char *tmp_haystack = (char*) haystack;
            while (*tmp_needle) {
                if (*tmp_haystack == *tmp_needle) {
                    tmp_needle++;
                    tmp_haystack++;
                } else {
                    tmp_needle = (char*) needle;
                    break;
                }
                if (!*tmp_needle) {
                    value_return = (char *) haystack;
                    break;
                }
            }
        }
    }
    return value_return;
}

char *s21_strtok(char *str, const char *delim) {
    static char *next = S21_NULL;
    if (str) {
      next = str;
    }
    if (next && *next == 0) {
      return S21_NULL;
    }
    char* c = next;
    if (c) {
        while (s21_strchr(delim, *c))
            c++;
    }
    if (c && *c == 0) {
      return S21_NULL;
    }
    char* word = c;
    if (c) {
        while (s21_strchr(delim, *c) == 0)
        c++;
    }
    if (c && *c == 0) {
      next = c;
      return word;
    }
    if (c) {
        *c = 0;
        next = c + 1;
    }
    return word;
}

void *s21_to_upper(const char *str) {
    char *str_up = S21_NULL;
    if (str != S21_NULL) {
        int size = s21_strlen(str) + 1;
        str_up = malloc(size * sizeof(char));
        int i;
        for (i = 0; str[i]; i++) {
            if (str[i] >= 97 && str[i] <= 122) {
                str_up[i] = str[i] - 32;
            } else {
                str_up[i] = str[i];
            }
        }
        str_up[i] = '\0';
    }
    return str_up;
}

void *s21_to_lower(const char *str) {
    char *str_low = S21_NULL;
    if (str != S21_NULL) {
        int size = s21_strlen(str) + 1;
        int i;
        str_low = malloc(size * sizeof(char));
        for (i = 0; str[i]; i++) {
            if (str[i] <= 90 && str[i] >= 65) {
                str_low[i] = str[i] + 32;
            } else {
                str_low[i] = str[i];
            }
        }
        str_low[i] = '\0';
    }
    return str_low;
}

void *s21_insert(const char *src, const char *str, S21_SIZE_T start_index) {
    char *new_str = NULL;
    if (src && str && s21_strlen(src) >= start_index) {
        new_str = (char *)malloc((s21_strlen(src) + s21_strlen(str) + 1) *
                                 sizeof(char));
        if (new_str) {
            s21_strncpy(new_str, src, start_index);
            *(new_str + start_index) = '\0';
            s21_strcat(new_str, str);
            s21_strcat(new_str, src + start_index);
        }
    }
    return (void *)new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *src_new = S21_NULL;
    if (src != S21_NULL && trim_chars != S21_NULL) {
        int size = s21_strlen(src) + 1;
        src_new = malloc(size * sizeof(char));
        int i = 0, k = size - 2, flag = 1, l;
        while (src[i] && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[i] == trim_chars[j]) {
                    flag = 1;
                    i++;
                    break;
                }
            }
        }
        flag = 1;
        while (k >=0 && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[k] == trim_chars[j]) {
                    flag = 1;
                    k--;
                    break;
                }
            }
        }
        k = k - i;
        for (l = 0; l <= k; i++, l++)
            src_new[l] = src[i];
        src_new[l] = '\0';
    }
    return src_new;
}

int s21_sscanf(char *str, const char *format, ...) {
    int i = 0;
    t_format_scan info;
    info.read_fail = 0;
    info.ret_value = 0;
    va_start(info.arg, format);
    while (format[i]) {
        if (format[i] == '%') {
            init_struct_scan(&info);
            i = check_flags_scan(&info, format, i + 1, &str);
            if (info.read_fail) {
                if (*str == 0)
                    info.ret_value = -1;
                break;
            }
        }
    }
    int ret = info.ret_value;
    va_end(info.arg);
    return ret;
}

void init_struct_scan(t_format_scan *info) {
    info->width = 0;
    info->l = 0;
    info->h = 0;
    info->hexadecimal = 0;
    info->scientific = 0;
    info->star = 0;
    info->octavian = 0;
}

int check_flags_scan(t_format_scan *info, const char *format, int i, char **str) {
    while (!is_specifier_scan(format[i]) && format[i]) {
        if (format[i] == '*') {
            info->star = 1;;
            i++;
        }
        if (format[i] == 'h') {
            info->h = format[i];
            i++;
        }
        if (format[i] == 'l') {
            info->l = format[i];
            i++;
        }
    }
    handle_specifier_scan(info, str, format[i]);
    return (i + 1);
}

int is_specifier_scan(char c) {
    int result = 0;
    if (c == 'd' || c == 'i' || c == 'f' || c == 'u' || c == 's'
        || c == 'c' || c == 'x' || c == 'X' || c == 'e' || c == 'E'
        || c == 'o' || c == 'p' || c == 'n' || c == 'g' || c == 'G')
        result = 1;
    return result;
}

void handle_specifier_scan(t_format_scan *info, char **str, char spec) {
    char *fake = S21_NULL;
    long long fake_nmb;
    switch (spec) {
        case 'o':
            info->octavian = 1;
            if (!info->star)
                info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
            else
                read_unsigned(str, (unsigned*)&fake_nmb, info);
            break;
        case 'i':
            skip_spaces(str);
            if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
                info->hexadecimal = 1;
                if (!info->star)
                    info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
                else
                    read_unsigned(str, (unsigned*)&fake_nmb, info);
            } else if (**str == '0') {
                info->octavian = 1;
                if (!info->star)
                    info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
                else
                    read_unsigned(str, (unsigned*)&fake_nmb, info);
            } else {
                if (!info->star)
                    info->ret_value += read_int(str, va_arg(info->arg, int*), info);
                else
                    read_int(str, (int*)&fake_nmb, info);
            }
            break;
        case 'd':
            if (info->l) {
                info->ret_value += read_long(str, va_arg(info->arg, long*), info);
            } else if (info->h) {
                info->ret_value += read_short(str, (short*)va_arg(info->arg, int*), info);
            } else {
                if (!info->star)
                    info->ret_value += read_int(str, va_arg(info->arg, int*), info);
                else
                    read_int(str, (int*)&fake_nmb, info);
            }
            break;
        case 'u':
            if (info->l) {
                info->ret_value += read_unsigned_long(str, va_arg(info->arg, unsigned long*), info);
            } else if (info->h) {
                info->ret_value += read_unsigned_short(str, (unsigned short*)va_arg(info->arg, int*), info);
            } else {
                if (!info->star)
                    info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
                else
                    read_unsigned(str, (unsigned*)&fake_nmb, info);
            }
            break;
        case 'x':
            info->hexadecimal = 1;
            if (!info->star)
                info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
            else
                read_unsigned(str, (unsigned*)&fake_nmb, info);
            break;
        case 'X':
            info->hexadecimal = 1;
            if (!info->star)
                info->ret_value += read_unsigned(str, va_arg(info->arg, unsigned*), info);
            else
                read_unsigned(str, (unsigned*)&fake_nmb, info);
            break;
        case 'p':
            info->hexadecimal = 1;
            if (!info->star)
                info->ret_value += read_ptr(str, (unsigned long*)va_arg(info->arg, void**), info);
            else
                read_ptr(str, (unsigned long*)&fake_nmb, info);
            break;
        case 'c':
            if (!info->star)
                info->ret_value += read_char(str, va_arg(info->arg, char *), info);
            else
                read_char(str, (char*)&fake_nmb, info);
            break;
        case 's':
            if (!info->star)
                info->ret_value += read_string(str, va_arg(info->arg, char *), info);
            else
                read_string(str, fake, info);
            break;
        case 'g':
        case 'G':
        case 'e':
        case 'E':
        case 'f':
            info->ret_value += read_float(str, info);
            break;
    }
}

int read_char(char **buff, char *target, t_format_scan *info) {
    int res = 0;
    if (**buff) {
        *target = **buff;
        res = 1;
        (*buff)++;
    } else {
        info->read_fail = 1;
        res = -1;
    }
    return res;
}

int read_string(char **buff, char *target, t_format_scan *info) {
    int res = 0;
    skip_spaces(buff);
    if (**buff == 0) {
        res = -1;
    } else {
        while (**buff != '\n' && **buff != ' ' && **buff != '\t' && **buff != 0) {
            !info->star ? (*target = **buff) : 0;
            target++;
            (*buff)++;
            res = 1;
        }
        if (!info->star)
            *target = 0;
    }
    if (res == 0 || res == -1)
        info->read_fail = 1;
    return res;
}

int read_unsigned(char **buff, unsigned *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    skip_spaces(buff);
    if (info->octavian) {
        if (**buff == '0')
            res = 1;
        check_valid_oct(buff, &res, &check, target);
        if (check) {
            *target = **buff - '0';
            (*buff)++;
        }
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff && check; (*buff)++) {
            if ((**buff >= '0' && **buff <= '8'))
                *target = *target * 8 + **buff - '0';
            else
                check = 0;
        }
    } else if (info->hexadecimal) {
        if (**buff == '0')
            res = 1;
        check_valid_hex(buff, &res, &check, target);
        if (check) {
            if (**buff >= 'A' && **buff <= 'F')
                *target = **buff - 55;
            else if (**buff >= 'a' && **buff <= 'f')
                *target = **buff - 87;
            else
                *target = **buff - '0';
            (*buff)++;
        }
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff && check; (*buff)++) {
            if ((**buff >= '0' && **buff <= '9') || (**buff >= 'A' && **buff <= 'F') ||
            (**buff >= 'a' && **buff <= 'f')) {
                if (**buff >= 'A' && **buff <= 'F')
                    *target = *target * 16 + **buff - 55;
                else if (**buff >= 'a' && **buff <= 'f')
                    *target = *target * 16 + **buff - 87;
                else
                    *target = *target * 16 + **buff - '0';
            } else {
                check = 0;
            }
        }
    } else {
        if (**buff == '0')
            res = 1;
        check_valid_unsigned(buff, &res, &check, target);
        if (check) {
            *target = **buff - '0';
            (*buff)++;
        }
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff && check; (*buff)++) {
            if (**buff >= '0' && **buff <= '9')
                *target = *target * 10 + **buff - '0';
            else
                check = 0;
        }
    }
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_int(char **buff, int *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    int neg = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_int(buff, &res, &check, target, &neg, info);
    if (check) {
        *target = **buff - '0';
        (*buff)++;
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff; (*buff)++) {
            if (**buff >= '0' && **buff <= '9')
                *target = *target * 10 + **buff - '0';
            else
                break;
        }
    }
    neg ? (*target *= -1) : 0;
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_long(char **buff, long *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    int neg = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_int(buff, &res, &check, (int*)target, &neg, info);
    if (check) {
        *target = **buff - '0';
        (*buff)++;
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff; (*buff)++) {
            if (**buff >= '0' && **buff <= '9')
                *target = *target * 10 + **buff - '0';
            else
                break;
        }
    }
    neg ? (*target *= -1) : 0;
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_unsigned_long(char **buff, unsigned long *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_unsigned_long(buff, &res, &check, target);
    if (check) {
        *target = **buff - '0';
        (*buff)++;
    }
    for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff && check; (*buff)++) {
        if (**buff >= '0' && **buff <= '9')
            *target = *target * 10 + **buff - '0';
        else
            check = 0;
    }
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_short(char **buff, short *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    int neg = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_int(buff, &res, &check, (int*)target, &neg, info);
    if (check) {
        *target = **buff - '0';
        (*buff)++;
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff; (*buff)++) {
            if (**buff >= '0' && **buff <= '9')
                *target = *target * 10 + **buff - '0';
            else
                break;
        }
    }
    neg ? (*target *= -1) : 0;
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_unsigned_short(char **buff, unsigned short *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    int neg = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_uns_short(buff, &res, &check, target);
    if (check) {
        *target = **buff - '0';
        (*buff)++;
        for (; **buff != ' ' && **buff != '\t' && **buff != '\n' && **buff; (*buff)++) {
            if (**buff >= '0' && **buff <= '9')
                *target = *target * 10 + **buff - '0';
            else
                break;
        }
    }
    neg ? (*target *= -1) : 0;
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_ptr(char **buff, unsigned long *target, t_format_scan *info) {
    int check = 0;
    int res = 0;
    skip_spaces(buff);
    if (**buff == '0')
        res = 1;
    check_valid_ptr(buff, &res, &check, target);
    if (check) {
        if (**buff >= 'A' && **buff <= 'F')
            *target = **buff - 55;
        else if (**buff >= 'a' && **buff <= 'f')
            *target = **buff - 87;
        else
            *target = **buff - '0';
        (*buff)++;
    }
    for (; **buff != ' ' && **buff != '\t' && **buff != '\n' &&
    **buff && check; (*buff)++) {
        if ((**buff >= '0' && **buff <= '9') || (**buff >= 'A' && **buff <= 'F')
        || (**buff >= 'a' && **buff <= 'f')) {
            if (**buff >= 'A' && **buff <= 'F')
                *target = *target * 16 + **buff - 55;
            else if (**buff >= 'a' && **buff <= 'f')
                *target = *target * 16 + **buff - 87;
            else
                *target = *target * 16 + **buff - '0';
        } else {
            check = 0;
        }
    }
    skip_spaces(buff);
    if (!res)
        info->read_fail = 1;
    return res;
}

int read_float(char **buff, t_format_scan *info) {
    int res = 0;
    skip_spaces(buff);
    if (**buff == 0) {
        res = -1;
    } else if ((**buff >= '0' && **buff <= '9') ||
                **buff == '-' || **buff == '+') {
        double value  = s21_atof(buff, info);
        double exp;
        if ((exp = scientific_presentation(buff)))
            value *= pow(10, exp);
        if (!info->star) {
            *va_arg(info->arg, double *) = value;
            res = 1;
        } else {
            res = 0;
        }
    }
    if ((res == 0 && !info->star) || res == -1)
        info->read_fail = 1;
    return res;
}

int scientific_presentation(char **buff) {
    int exp = 0;
    if ((**buff == 'e' || **buff == 'E') && (*(*buff + 1) == '+' || *(*buff + 1) == '-')
    && *(*buff + 2) >= '0' && *(*buff + 2) <= '9'
    && *(*buff + 3) >= '0' && *(*buff + 3) <= '9') {
        exp = (*(*buff + 2) - '0') * 10 + (*(*buff + 3) - '0');
        if (*(*buff + 1) == '-')
            exp *= -1;
        *buff += 4;
    }
    return exp;
}

double s21_atof(char **buff, t_format_scan *info) {
    if (info->width)
     {;}
    double value = 0, scale = 1;
    int afterpoint = 0, negative = 0;
    if (**buff == '-') {
        negative = 1;
        (*buff)++;
    } else if (**buff == '+') {
        (*buff)++;
    }
    while ((**buff >= '0' && **buff <= '9') || **buff == '.') {
        if (afterpoint) {
            scale = scale / 10;
            value = value + (**buff - '0') * scale;
        } else if (**buff == '.') {
            afterpoint = 1;
        } else {
            value = value * 10.0 + (**buff - '0');
        }
        (*buff)++;
    }
    if (negative)
        value *= -1;
    return value;
}

void skip_zeros_long(char **buff, long long *target) {
    while (**buff == '0') {
        (*buff)++;
        *target = 0;
    }
}

void skip_zeros_int(char **buff, int *target) {
    while (**buff == '0') {
        (*buff)++;
        *target = 0;
    }
}

void skip_zeros_short(char **buff, short *target) {
    while (**buff == '0') {
        (*buff)++;
        *target = 0;
    }
}

void skip_spaces(char **buff) {
    while (**buff == ' ' || **buff == '\t' || **buff == '\n')
        (*buff)++;
}

void check_valid_hex(char **buff, int *res, int *check, unsigned *target) {
    if (**buff == '0' && (*(*buff + 1) == 'x' || *(*buff + 1) == 'X')) {
            *buff = *buff + 2;
            skip_zeros_int(buff, (int*)target);
    }
    skip_zeros_int(buff, (int*)target);
    if ((**buff > '0' && **buff <= '9') || (**buff >= 'A' && **buff <= 'F')
    || (**buff >= 'a' && **buff <= 'f')) {
        *check = 1;
        *res = 1;
    }
}

void check_valid_unsigned(char **buff, int *res, int *check, unsigned *target) {
    skip_zeros_int(buff, (int*)target);
    if (**buff > '0' && **buff <= '9') {
        *check = 1;
        *res = 1;
    }
}

void check_valid_unsigned_long(char **buff, int *res, int *check, unsigned long *target) {
    skip_zeros_long(buff, (long long*)target);
    if (**buff > '0' && **buff <= '9') {
        *check = 1;
        *res = 1;
    }
}

void check_valid_uns_short(char **buff, int *res, int *check, unsigned short *target) {
    skip_zeros_short(buff, (short*)target);
    if (**buff > '0' && **buff <= '9') {
        *check = 1;
        *res = 1;
    }
}

void check_valid_int(char **buff, int *res, int *check, int *target, int *neg, t_format_scan *info) {
    if (**buff == '-') {
        (*buff)++;
        if (info->l)
            skip_zeros_long(buff, (long long*)target);
        else if (info->h)
            skip_zeros_short(buff, (short*)target);
        else
            skip_zeros_int(buff, (int*)target);
        if (**buff > '0' && **buff <= '9') {
            *check = 1;
            *res = 1;
            *neg = 1;
        }
    } else {
        if (info->l)
            skip_zeros_long(buff, (long long*)target);
        else if (info->h)
            skip_zeros_short(buff, (short*)target);
        else
            skip_zeros_int(buff, (int*)target);
        if (**buff > '0' && **buff <= '9') {
            *check = 1;
            *res = 1;
        }
    }
}

void check_valid_oct(char **buff, int *res, int *check, unsigned *target) {
    skip_zeros_int(buff, (int*)target);
    if (**buff > '0' && **buff <= '8') {
        *check = 1;
        *res = 1;
    }
}

void check_valid_ptr(char **buff, int *res, int *check, unsigned long *target) {
    if (**buff == '0' && (*(*buff + 1) == 'x' || *(*buff + 1) == 'X')) {
            *buff = *buff + 2;
            skip_zeros_long(buff, (long long*)target);
    }
    skip_zeros_long(buff, (long long*)target);
    if ((**buff > '0' && **buff <= '9') || (**buff >= 'A' && **buff <= 'F')
    || (**buff >= 'a' && **buff <= 'f')) {
        *check = 1;
        *res = 1;
    }
}

int s21_sprintf(char *str, const char *format, ...) {
    int i = 0 , j = 0;
    t_format info;
    va_start(info.arg, format);
    while (format[i]) {
        if (format[i] == '%') {
            init_struct(&info);
            i = check_flags(&info, format, i + 1, str, &j);
        } else {
            str[j++] = format[i++];
        }
    }
    str[j] = 0;
    va_end(info.arg);
    return j;
}

void init_struct(t_format *info) {
    info->zero = 0;
    info->precision = 0;
    info->minus = 0;
    info->padding = 0;
    info->plus = 0;
    info->point = 0;
    info->sign = 0;
    info->space = 0;
    info->width = 0;
    info->nmb_len = 0;
    info->is_negative = 0;
    info->l = 0;
    info->h = 0;
    info->upper_case = 0;
    info->hexadecimal = 0;
    info->octavian = 0;
    info->scientific = 0;
    info->ptr_val = 0;
    info->get_ptr = 0;
    info->sharp = 0;
    info->L = 0;
}

int check_flags(t_format *info, const char *format, int i, char *str, int *j) {
    char tmp_buf[10] = "";
    int buf_i;
    while (!is_specifier(format[i]) && format[i]) {
        if (format[i] == '-') {
            info->minus = 1;
            i++;
        }
        if (format[i] == '+') {
            info->plus = 1;
            i++;
        }
        if (format[i] == ' ') {
            info->space = 1;
            i++;
        }
        if (format[i] == '0') {
            info->zero = 1;
            i++;
        }
        if (format[i] == '*') {
            info->width = va_arg(info->arg, int);
            i++;
            if (info->width < 0) {
                info->minus = 1;
                info->width *= -1;
            }
        }
        if (format[i] >= '0' && format[i] <= '9') {
            buf_i = 0;
            while (format[i] >= '0' && format[i] <= '9' && buf_i < 9) {
                tmp_buf[buf_i++] = format[i++];
            }
            tmp_buf[buf_i] = 0;
            info->width = s21_atoi(tmp_buf);
        }
        if (format[i] == '.') {
            info->point = 1;
            i++;
            if (format[i] == '*') {
                info->precision = va_arg(info->arg, int);
                i++;
            } else {
                if (format[i] >= '0' && format[i] <='9') {
                    buf_i = 0;
                    while (format[i] >= '0' && format[i] <= '9' && buf_i < 9) {
                        tmp_buf[buf_i++] = format[i++];
                    }
                    tmp_buf[buf_i] = 0;
                    info->precision = s21_atoi(tmp_buf);
                }
            }
        }
        if (format[i] == 'h') {
            info->h = format[i];
            i++;
        }
        if (format[i] == 'l') {
            info->l = format[i];
            i++;
        }
        if (format[i] == '#')
            info->sharp = format[i++];
        if (format[i] == 'L')
            info->L = format[i++];
    }
    handle_specifier(info, str, j, format[i]);
    return (i + 1);
}

int is_specifier(char c) {
    int result = 0;
    if (c == 'd' || c == 'i' || c == 'f' || c == 'u' || c == 's'
        || c == 'c' || c == 'x' || c == 'X' || c == 'e' || c == 'E'
        || c == 'o' || c == 'p' || c == 'n' || c == '%' || c == 'g' || c == 'G')
        result = 1;
    return result;
}

void handle_specifier(t_format *info, char *str, int *j, char spec) {
    long double long_dbl_nmb;
    double dbl_nmb;
    switch (spec) {
        case 'c':
            if (info->l)
                add_wchar(str, j, info);
            else
                add_char(str, j, info);
            break;
        case 'd':
        case 'i':
            if (info->l)
                add_long(str, j, info);
            else if (info->h)
                add_short(str, j, info);
            else
                add_int(str, j, info);
            break;
        case 'u':
            if (info->l)
                add_unsigned_long(str, j, info);
            else if (info->h)
                add_unsigned_short(str, j, info);
            else
                add_unsigned(str, j, info);
            break;
        case 'x':
            info->hexadecimal = 1;
            if (info->l)
                add_unsigned_long(str, j, info);
            else if (info->h)
                add_unsigned_short(str, j, info);
            else
                add_unsigned(str, j, info);
            break;
        case 'X':
            info->hexadecimal = 1;
            info->upper_case = 1;
            if (info->l)
                add_unsigned_long(str, j, info);
            else if (info->h)
                add_unsigned_short(str, j, info);
            else
                add_unsigned(str, j, info);
            break;
        case 'o':
            info->octavian = 1;
            if (info->l)
                add_unsigned_long(str, j, info);
            else if (info->h)
                add_unsigned_short(str, j, info);
            else
                add_unsigned(str, j, info);
            break;
        case 'p':
            info->hexadecimal = 1;
            info->sharp = 1;
            info->ptr_val = (long unsigned)va_arg(info->arg, void *);
            info->get_ptr = 1;
            add_unsigned_long(str, j, info);
            break;
        case 's':
            if (info->l)
                add_Wstring(str, j, info);
            else
                add_string(str, j, info);
            break;
        case 'g':
            if (info->L) {
                long_dbl_nmb = va_arg(info->arg, long double);
                choose_presentation(info, long_dbl_nmb, str, j);
            } else {
                dbl_nmb = va_arg(info->arg, double);
                choose_presentation(info, dbl_nmb, str, j);
            }
            break;
        case 'G':
            info->upper_case = 1;
            if (info->L) {
                long_dbl_nmb = va_arg(info->arg, long double);
                choose_presentation(info, long_dbl_nmb, str, j);
            } else {
                dbl_nmb = va_arg(info->arg, double);
                choose_presentation(info, dbl_nmb, str, j);
            }
            break;
        case 'f':
            if (info->L)
                add_long_float(str, j, info);
            else
                add_double(str, j, info);
            break;
        case 'e':
            info->scientific = 1;
            if (info->L)
                add_long_float(str, j, info);
            else
                add_double(str, j, info);
            break;
        case 'E':
            info->scientific = 1;
            info->upper_case = 1;
            if (info->L)
                add_long_float(str, j, info);
            else
                add_double(str, j, info);
            break;
        case 'n':
            *va_arg(info->arg, int *) = *j;
            break;
        case '%':
            str[(*j)++] = '%';
            break;
    }
}

void choose_presentation(t_format *info, long double nmb, char *str, int *j) {
    char tmp_sci[50] = "";
    if (nmb < 0) {
        nmb *= -1;
        info->is_negative = 1;
    }
    int exp = ftoa_scientific(nmb, tmp_sci, info);
    if (exp >= -4 && exp < info->precision) {
        char tmp_fl[50] = "";
        ftoa(nmb, tmp_fl, info);
        if (tmp_fl[0] == '0' && info->precision)
            info->precision += 2;
        make_precision_for_g(tmp_fl, info);
        trunctacte_zeroes(tmp_fl, info);
        info->nmb_len = s21_strlen(tmp_fl);
        add_flags(str, j, info, tmp_fl, 0);
    } else {
        if (!info->precision && info->point)
            info->precision = 1;
        info->scientific = 1;
        info->nmb_len = s21_strlen(tmp_sci);
        char expo_part[5];
        s21_strcpy(expo_part, &tmp_sci[info->nmb_len - 4]);
        make_precision_for_g(tmp_sci, info);
        trunctacte_zeroes(tmp_sci, info);
        s21_strcat(tmp_sci, expo_part);
        info->nmb_len = s21_strlen(tmp_sci);
        add_flags(str, j, info, tmp_sci, 0);
    }
}

void make_precision_for_g(char *tmp, t_format *info) {
    int curr_nmb = 0;
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] != '.')
            curr_nmb++;
        if (curr_nmb == info->precision && tmp[i] != '.' && info->precision != 1) {
            if (tmp[i + 1] == '.' && tmp[i + 2] >= '5')
                increase_rank(tmp, i);
            else if (tmp[i + 1] >= '5')
                increase_rank(tmp, i);
        }
        if (curr_nmb > info->precision || (curr_nmb == info->precision && tmp[i] == '.' && !info->sharp)) {
            tmp[i] = 0;
            break;
        }
    }
}

void trunctacte_zeroes(char *buff, t_format *info) {
    int point_flag = 0;
    int only_zeroes_flag = 1;
    int numbers = 0;
    char *tmp = S21_NULL;
    while (*buff) {
        if (*buff != '.')
            numbers++;
        if (point_flag && *buff == '0' && (numbers >= info->precision || info->scientific) && !info->sharp) {
            tmp = buff;
            while (*tmp) {
                if (*tmp != '0') {
                    only_zeroes_flag = 0;
                    break;
                }
                tmp++;
            }
            if (only_zeroes_flag) {
                *buff = 0;
                return;
            }
        }
        if (*buff == '.')
            point_flag = 1;
        buff++;
    }
}

void increase_rank(char *tmp, int index) {
    if (index >= 0) {
        if (tmp[index] == '.') {
            increase_rank(tmp, index - 2);
        } else {
            tmp[index]++;
            if (tmp[index] == 58) {
                increase_rank(tmp, index - 1);
                tmp[index] = '0';
            }
        }
    }
}

void add_char(char *str, int *j, t_format *info) {
    if (info->width) {
        if (info->minus) {
            str[(*j)++] = (char)va_arg(info->arg, int);
            add_spaces_or_zeros(info->width - 1, ' ', str, j);
        } else {
            add_spaces_or_zeros(info->width - 1, ' ', str, j);
            str[(*j)++] = (char)va_arg(info->arg, int);
        }
    } else {
        str[(*j)++] = (char)va_arg(info->arg, int);
    }
}

void add_wchar(char *str, int *j, t_format *info) {
    if (info->width) {
        if (info->minus) {
            str[(*j)++] = (wchar_t)va_arg(info->arg, wchar_t);
            add_spaces_or_zeros(info->width - 1, ' ', str, j);
        } else {
            add_spaces_or_zeros(info->width - 1, ' ', str, j);
            str[(*j)++] = (wchar_t)va_arg(info->arg, wchar_t);
        }
    } else {
        str[(*j)++] = (wchar_t)va_arg(info->arg, wchar_t);
    }
}

void add_string(char *str, int *j, t_format *info) {
    char *ptr;
    ptr = va_arg(info->arg, char *);
    int str_len;
    if (ptr != S21_NULL)
        str_len = s21_strlen(ptr);
    else
        str_len = s21_strlen("(null)");
    if (info->point && !info->precision)
        str_len = 0;
    if (info->width) {
        if (info->minus) {
            if (info->precision && info->precision < str_len)
                str_len = info->precision;
            add_string_to_buff(str, j, str_len, ptr);
            add_spaces_or_zeros(info->width - str_len, ' ', str, j);
        } else {
            if (info->precision && info->precision < str_len)
                str_len = info->precision;
            add_spaces_or_zeros(info->width - str_len, ' ', str, j);
            add_string_to_buff(str, j, str_len, ptr);
        }
    } else {
        if (info->precision && info->precision < str_len)
                str_len = info->precision;
        add_string_to_buff(str, j, str_len, ptr);
    }
}

void add_Wstring(char *str, int *j, t_format *info) {
    wchar_t *ptr;
    ptr = va_arg(info->arg, wchar_t *);
    int str_len;
    char buff[1000];
    int i = 0;
    while (*ptr && ptr) {
        buff[i++] = (char)(*ptr);
        ptr++;
    }
    buff[i] = 0;
    str_len = s21_strlen(buff);
    if (info->point && !info->precision)
        str_len = 0;
    if (info->width) {
        if (info->minus) {
            if (info->precision && info->precision < str_len)
                str_len = info->precision;
            add_string_to_buff(str, j, str_len, buff);
            add_spaces_or_zeros(info->width - str_len, ' ', str, j);
        } else {
            if (info->precision && info->precision < str_len)
                str_len = info->precision;
            add_spaces_or_zeros(info->width - str_len, ' ', str, j);
            add_string_to_buff(str, j, str_len, buff);
        }
    } else {
        if (info->precision && info->precision < str_len)
                str_len = info->precision;
        add_string_to_buff(str, j, str_len, buff);
    }
}

void add_string_to_buff(char *str, int *j, int str_len, char *ptr) {
    if (ptr != S21_NULL)
        s21_strncpy(&str[(*j)], ptr, str_len);
    else
        s21_strncpy(&str[(*j)], "(null)", str_len);
    (*j) += str_len;
}

void add_int(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    int nmb = (int)va_arg(info->arg, int);
    if (nmb < 0) {
        info->is_negative = 1;
        nmb *= -1;
    }
    if (nmb < 0)
        s21_strcat(tmp, "2147483648");
    else
        itoa_unsigned(nmb, tmp, 10, 0, info);
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_flags(char *str, int *j, t_format *info, char *tmp, int flag_is_int) {
    int field_len = info->nmb_len;
    if (info->is_negative)
        field_len++;
    int nmb_zero_to_print = 0;
    if (info->precision && info->precision < info->nmb_len && flag_is_int)
        info->precision = info->nmb_len;
    if (info->precision && info->precision > info->nmb_len && flag_is_int)
        nmb_zero_to_print = info->precision - info->nmb_len;
    if (info->sharp) {
        if (info->hexadecimal) {
            field_len += 2;
        } else if (info->octavian) {
            field_len += 2;
            nmb_zero_to_print -= 1;
        }
    }
    if (info->width) {
        if (info->minus) {
            if (info->plus && !info->is_negative)
                add_flag_modifier(str, j, &field_len, '+', 1);
            else if (info->space && !info->is_negative)
                add_flag_modifier(str, j, &field_len, ' ', 1);
            if (info->is_negative && !info->zero)
                add_flag_modifier(str, j, &field_len, '-', 0);
            check_sharp_modifier(str, j, info);
            for (int i = 0; i < nmb_zero_to_print; i++)
                add_flag_modifier(str, j, &field_len, '0', 0);
            s21_strcpy(&str[(*j)], tmp);
            (*j) += info->nmb_len;
            add_spaces_or_zeros(info->width - field_len - nmb_zero_to_print, ' ', str, j);
        } else {
            if ((info->plus || info->space) && !info->is_negative)
                field_len++;
            if (info->plus && !info->is_negative && info->zero)
                add_flag_modifier(str, j, &field_len, '+', 0);
            else if (info->space && !info->is_negative && info->zero)
                add_flag_modifier(str, j, &field_len, ' ', 0);
            else if (info->is_negative && info->zero)
                add_flag_modifier(str, j, &field_len, '-', 0);
            if (info->zero) {
                check_sharp_modifier(str, j, info);
                add_spaces_or_zeros(info->width - field_len - nmb_zero_to_print, '0', str, j);
           } else {
                add_spaces_or_zeros(info->width - field_len - nmb_zero_to_print, ' ', str, j);
           }
            if (info->plus && !info->is_negative && !info->zero)
                add_flag_modifier(str, j, &field_len, '+', 0);
            else if (info->space && !info->is_negative && !info->zero)
                add_flag_modifier(str, j, &field_len, ' ', 0);
            else if (info->is_negative && !info->zero)
                add_flag_modifier(str, j, &field_len, '-', 0);
            if (!info->zero)
                check_sharp_modifier(str, j, info);
            add_spaces_or_zeros(nmb_zero_to_print, '0', str, j);
            s21_strcpy(&str[(*j)], tmp);
            (*j) += info->nmb_len;
        }
    } else {
        if (info->plus && !info->is_negative)
            add_flag_modifier(str, j, &field_len, '+', 1);
        else if (info->space && !info->is_negative)
            add_flag_modifier(str, j, &field_len, ' ', 1);
        if (info->is_negative)
            add_flag_modifier(str, j, &field_len, '-', 0);
        check_sharp_modifier(str, j, info);
        for (int i = 0; i < nmb_zero_to_print; i++)
            add_flag_modifier(str, j, &field_len, '0', 0);
        s21_strcpy(&str[(*j)], tmp);
        (*j) += info->nmb_len;
    }
}

void check_sharp_modifier(char *str, int *j, t_format *info) {
    if (info->sharp && info->hexadecimal) {
        if (info->upper_case) {
            s21_strcpy(&str[(*j)], "0X");
            *j += 2;
        } else {
            s21_strcpy(&str[(*j)], "0x");
            *j += 2;
        }
    } else if (info->sharp && info->octavian) {
        s21_strcpy(&str[(*j)], "0");
        *j += 1;
    }
}

void add_flag_modifier(char *str, int *j, int *field_len, char sign, int inc_field_flag) {
    str[(*j)] = sign;
    (*j)++;
    if (inc_field_flag)
        (*field_len)++;
}

void add_spaces_or_zeros(int number_of_spaces, char c, char *str, int *j) {
    for (int i = 0; i < number_of_spaces; i++) {
        str[(*j)] = c;
        (*j)++;
    }
}

void add_short(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    short nmb = (short)va_arg(info->arg, int);
    if (nmb < 0) {
        info->is_negative = 1;
        nmb *= -1;
    }
    itoa_unsigned(nmb, tmp, 10, 0, info);
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_long(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    long long nmb = va_arg(info->arg, long long);
    if (nmb < 0) {
        info->is_negative = 1;
        nmb *= -1;
    }
    itoa_unsigned(nmb, tmp, 10, 0, info);
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_unsigned(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    unsigned int nmb = (unsigned)va_arg(info->arg, unsigned);
    if (info->hexadecimal) {
        if (info->upper_case)
            itoa_unsigned(nmb, tmp, 16, 1, info);
        else
            itoa_unsigned(nmb, tmp, 16, 0, info);
    } else if (info->octavian) {
        itoa_unsigned(nmb, tmp, 8, 0, info);
    } else {
        itoa_unsigned(nmb, tmp, 10, 0, info);
    }
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_unsigned_short(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    unsigned short nmb = (unsigned short)va_arg(info->arg, int);
    if (info->hexadecimal) {
        if (info->upper_case)
            itoa_unsigned(nmb, tmp, 16, 1, info);
        else
            itoa_unsigned(nmb, tmp, 16, 0, info);
    } else if (info->octavian) {
        itoa_unsigned(nmb, tmp, 8, 0, info);
    } else {
        itoa_unsigned(nmb, tmp, 10, 0, info);
    }
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_unsigned_long(char *str, int *j, t_format *info) {
    char tmp[30] = "";
    unsigned long nmb;
    if (info->ptr_val || info->get_ptr)
        nmb = info->ptr_val;
    else
        nmb = (unsigned long)va_arg(info->arg, long int);
    if (info->hexadecimal) {
        if (info->upper_case)
            itoa_unsigned(nmb, tmp, 16, 1, info);
        else
            itoa_unsigned(nmb, tmp, 16, 0, info);
    } else if (info->octavian) {
        itoa_unsigned(nmb, tmp, 8, 0, info);
    } else {
        itoa_unsigned(nmb, tmp, 10, 0, info);
    }
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 1);
}

void add_double(char *str, int *j, t_format *info) {
    char tmp[50] = "";
    double nmb = va_arg(info->arg, double);
    if (nmb < 0) {
        info->is_negative = 1;
        nmb *= -1;
    }
    if (info->scientific)
        ftoa_scientific(nmb, tmp, info);
    else
        ftoa(nmb, tmp, info);
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 0);
}

void add_long_float(char *str, int *j, t_format *info) {
    char tmp[50] = "";
    long double nmb = va_arg(info->arg, long double);
    if (nmb < 0) {
        info->is_negative = 1;
        nmb *= -1;
    }
    if (info->scientific)
        ftoa_scientific(nmb, tmp, info);
    else
        ftoa(nmb, tmp, info);
    info->nmb_len = s21_strlen(tmp);
    add_flags(str, j, info, tmp, 0);
}

int itoa_unsigned(unsigned long n, char *tmp, int radix, int upper_case, t_format *info) {
    if (n == 0 && info->get_ptr == 0)
        info->sharp = 0;
    char a = 'a';
    if (upper_case)
        a = 'A';
    int i = 0;
    if (!(info->point && !info->precision && (info->octavian || info->hexadecimal)) ||
        (info->width && info->point && !info->precision)) {
        do {
            unsigned int remainder = n % radix;
            if (remainder > 9)
                tmp[i] = remainder + a - 10;
            else
                tmp[i] = remainder + '0';
            i++;
        } while ((n /= radix) > 0);
        tmp[i] = 0;
        reverse(tmp);
    }
    return i;
}

void ftoa(long double float_nmb, char *tmp, t_format *info) {
    if (info->precision < 0 || !info->point) {
        info->point = 1;
        info->precision = 6;
    }
    unsigned long int_part = 0;
    int_part = !info->precision ? (unsigned long int)round(float_nmb) : (unsigned long)float_nmb;
    long double float_part = float_nmb - int_part;
    int i = itoa_unsigned(int_part, tmp, 10, 0, info);
    if (info->precision || info->sharp)
        tmp[i++] = '.';
    tmp[i] = 0;
    int precision = info->precision;
    if (precision) {
        while (precision--)
            float_part *= 10;
        char float_buff[50] = {0};
        int float_len = itoa_unsigned((unsigned long)round(float_part), float_buff, 10, 0, info);
        while (float_len++ < info->precision)
            s21_strcat(tmp, "0");
        s21_strcat(tmp, float_buff);
    }
}

int ftoa_scientific(long double float_nmb, char *tmp, t_format *info) {
    if (info->precision < 0 || !info->point) {
        info->point = 1;
        info->precision = 6;
    }
    int exp = normalize(&float_nmb);
    unsigned long int_part = 0;
    int_part = !info->precision ? (unsigned long int)round(float_nmb) : (unsigned long)float_nmb;
    long double float_part = float_nmb - int_part;
    int i = itoa_unsigned(int_part, tmp, 10, 0, info);
    if (info->precision || info->sharp)
        tmp[i++] = '.';
    tmp[i] = 0;
    int precision = info->precision;
    if (precision) {
        while (precision--)
            float_part *= 10;
        char float_buff[30] = "";
        int float_len = itoa_unsigned((unsigned long)round(float_part), float_buff, 10, 0, info);
        while (float_len++ < info->precision)
            s21_strcat(tmp, "0");
        s21_strcat(tmp, float_buff);
    }
    char expo_buffer[30] = "";
    char e;
    if (info->upper_case)
        e = 'E';
    else
        e = 'e';
    s21_sprintf(expo_buffer, "%c%+.2d", e, exp);
    s21_strcat(tmp, expo_buffer);
    return exp;
}

int s21_atoi(char *str) {
    int result = 0;
    for (int i = 0; str[i]; i++) {
        result = result * 10 + str[i] - '0';
    }
    return result;
}

void reverse(char *tmp) {
    int i, j;
    for (i = 0, j = s21_strlen(tmp) - 1; i < j; i++, j--) {
        char c = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = c;
    }
}

int normalize(long double *val) {
    int exponent = 0;
    long double value = *val;
    if (value != 0) {
        while (value >= 10.0) {
            value /= 10.0;
            ++exponent;
        }

        while (value < 1.0) {
            value *= 10.0;
            --exponent;
        }
        *val = value;
    }
    return exponent;
}
