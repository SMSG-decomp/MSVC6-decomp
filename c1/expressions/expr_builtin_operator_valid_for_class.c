bool __cdecl expr_builtin_operator_valid_for_class(byte op,char form,int is_left)

{
  if (form == '\x01') {
    if ((op != 0x31) && (op != 0x76)) {
      return (&g_token_class)[op] == '=';
    }
  }
  else if (form == '\x02') {
    switch(op) {
    case 0x34:
    case 0x36:
    case 0x37:
    case 0x74:
      break;
    default:
      return false;
    case 0x56:
      return is_left == 0;
    }
  }
  return true;
}

