c1_yystype * __cdecl yyparse_c_value_for_token(c1_yystype *value,int kind)

{
  int iVar1;
  c1_u32 *pcVar2;
  c1_yystype *pcVar3;
  c1_u32 local_18 [3];
  c1_type *local_c;
  
  if (kind == 6) {
    local_18[0] = 0;
  }
  else if (kind == 0x1f) {
    local_c = g_type_none;
    goto LAB_106313be;
  }
  local_18[0] = CONCAT31(local_18[0]._1_3_,(char)kind);
LAB_106313be:
  pcVar2 = local_18;
  pcVar3 = value;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3->words[0] = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = (c1_yystype *)&(pcVar3->string).length;
  }
  return value;
}

