c1_yystype * __cdecl asm_parser_value_for_token(c1_yystype *value,int kind)

{
  int iVar1;
  c1_u32 *pcVar2;
  c1_yystype *pcVar3;
  c1_u32 local_18 [3];
  c1_type *local_c;
  
  switch(kind) {
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2f:
  case 0x30:
  case 0x31:
    local_18[0] = 0;
    local_18[1] = 0;
    break;
  case 0x2b:
    local_c = g_type_none;
    break;
  case 0x2c:
    local_18[0] = 0;
    break;
  case 0x2d:
    local_18[2] = 0;
    local_c = (c1_type *)0x0;
    break;
  default:
    local_18[0] = kind;
    local_18[1] = kind >> 0x1f;
  }
  pcVar2 = local_18;
  pcVar3 = value;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3->words[0] = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = (c1_yystype *)&(pcVar3->string).length;
  }
  return value;
}

