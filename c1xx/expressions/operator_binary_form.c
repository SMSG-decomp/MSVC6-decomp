c1_u8 __cdecl operator_binary_form(c1_u8 token)

{
  switch(token) {
  case '1':
  case '2':
  case '3':
  case '7':
  case '8':
  case '9':
  case ':':
  case ';':
  case '>':
  case '?':
  case '@':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'J':
  case 'K':
  case 'L':
  case 'M':
  case 'N':
  case 'O':
  case 'Q':
  case 'R':
  case 'W':
  case 'X':
  case '[':
  case '\\':
  case 0x92:
  case 0x93:
    break;
  default:
    token = '\x01';
  }
  return token;
}

