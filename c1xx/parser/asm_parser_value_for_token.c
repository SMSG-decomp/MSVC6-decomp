c1_yy_value * __cdecl asm_parser_value_for_token(c1_yy_value *value,int kind)

{
  int iVar1;
  c1_u32 *pcVar2;
  c1_yy_value *pcVar3;
  c1_u32 local_28 [6];
  c1_type *local_10;
  
  switch(kind) {
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2f:
  case 0x30:
  case 0x31:
    local_28[0] = 0;
    local_28[1] = 0;
    break;
  case 0x2b:
    local_10 = g_type_none;
    break;
  case 0x2c:
    local_28[0] = 0;
    break;
  case 0x2d:
    local_28[2] = 0;
    local_28[3] = 0;
    break;
  default:
    local_28[0] = kind;
    local_28[1] = kind >> 0x1f;
  }
  pcVar2 = local_28;
  pcVar3 = value;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3->words[0] = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = (c1_yy_value *)(pcVar3->words + 1);
  }
  return value;
}

