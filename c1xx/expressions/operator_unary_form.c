c1_u8 __cdecl operator_unary_form(c1_u8 token)

{
  switch(token) {
  case '1':
    return '1';
  default:
    return '\x01';
  case '8':
    return 'T';
  case '<':
    return '<';
  case '@':
    return 'U';
  case 'F':
    return 'Z';
  case 'J':
    return '=';
  case 'Q':
    return 0x86;
  case 'Y':
    return 'Y';
  }
}

