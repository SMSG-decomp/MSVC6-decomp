char * __cdecl type_keyword_text(ushort code)

{
  if ((code & 0x10) == 0) {
    if ((code & 0x20) == 0) {
      if ((code & 0x200) == 0) {
        if ((code & 0x100) != 0) {
          return "enum";
        }
        if ((code & 0x40) != 0) {
          return "void";
        }
        if ((code & 0x400) != 0) {
          return "__segment";
        }
        if (code == 0x80d) {
          return "...";
        }
      }
      else if ((g_format_omit_tag_keyword & 1) == 0) {
        if (code == 0x201) {
          return "class";
        }
        if (code == 0x202) {
          return "struct";
        }
        if (code == 0x203) {
          return "union";
        }
      }
    }
    else {
      if (code == 0x26) {
        return "float";
      }
      if (code == 0x27) {
        return "double";
      }
      if (code == 0x28) {
        return "long double";
      }
    }
  }
  else {
    switch(code & 0x1f) {
    case 0x11:
      return "char";
    case 0x12:
      return "short";
    case 0x13:
      return "int";
    case 0x14:
      return "long";
    }
    switch(code & 0x1f) {
    case 0x19:
      return "__int8";
    case 0x1a:
      return "__int16";
    case 0x1b:
      return "__int32";
    case 0x1c:
      return "__int64";
    case 0x1d:
      return "__int128";
    }
  }
  return "";
}

