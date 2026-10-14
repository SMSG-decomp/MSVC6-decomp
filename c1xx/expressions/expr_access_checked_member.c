c1_node * __cdecl
expr_access_checked_member(uint op,c1_node *obj,c1_symbol *member,int sign,c1_type *type)

{
  int *path;
  char cVar1;
  c1_node *pcVar2;
  
  path = *(int **)member->type;
  if (g_token_class[op & 0xff] == 'd') {
    cVar1 = access_check_member_path(member);
    if (cVar1 == '\0') {
      pcVar2 = conv_report_inaccessible_conversion(op,obj,op & 0xff,type,path,sign);
      return pcVar2;
    }
  }
  else {
    access_check_member(member);
  }
  pcVar2 = expr_member_offset(op,obj,path,(char)sign,type);
  return pcVar2;
}

