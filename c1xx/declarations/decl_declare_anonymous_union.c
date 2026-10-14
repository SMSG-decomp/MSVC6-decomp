void __cdecl decl_declare_anonymous_union(c1xx_decl_specifiers *spec)

{
  byte bVar1;
  c1_symbol *object;
  c1_symbol *pcVar2;
  c1_sym_link *first;
  int iVar3;
  int iVar4;
  char local_18 [4];
  int local_14;
  int local_10;
  int local_c;
  fe_name **local_8;
  int iter_filter;
  
  class_check_anonymous_union(spec->spec);
  object = decl_declare_anonymous_union_object(spec);
  if (object == (c1_symbol *)0x0) {
    return;
  }
  if ((object->type->code & 0x200) == 0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = (object->type->extra).cls;
  }
  if ((pcVar2->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((pcVar2->x28).members)->head;
  }
  list_cursor_init(local_18,first);
  local_c = 0;
  iter_filter = 1;
  iVar3 = local_14;
  local_8 = &pcVar2->name;
  if (local_18[0] != '\0') {
    local_c = local_14;
  }
LAB_1046aea8:
  local_10 = local_c;
  if (local_c == 0) {
    decl_anonymous_union_done_nop(object);
    return;
  }
  if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 4), local_14 = iVar3, local_c = iVar3, iVar3 == 0))
  {
    local_c = 0;
  }
  switch(iter_filter) {
  case 0:
    goto LAB_1046aefe;
  case 1:
    bVar1 = *(byte *)(local_10 + -8) & 0x1f;
    if (((bVar1 == 3) || (bVar1 == 2)) && ((*(byte *)(local_10 + -5) & 1) == 0)) goto LAB_1046aefe;
    goto LAB_1046aea8;
  case 2:
    iVar3 = sym_is_member_function_or_class_alias((c1_symbol *)(local_10 + -8));
    bVar1 = (byte)iVar3;
    iVar3 = local_14;
    break;
  case 3:
    bVar1 = (*(byte *)(local_10 + -8) & 0x1f) == 4;
    break;
  default:
    goto LAB_1046aea8;
  case 5:
    iVar4 = sym_is_member_function_or_class_alias((c1_symbol *)(local_10 + -8));
    iVar3 = local_14;
    if ((char)iVar4 == '\0') goto LAB_1046aea8;
    bVar1 = *(byte *)(local_10 + -7) & 0x40;
  }
  if (bVar1 != 0) {
LAB_1046aefe:
    decl_declare_anonymous_union_member(object,(c1_symbol *)(local_10 + -8),spec);
    iVar3 = local_14;
  }
  goto LAB_1046aea8;
}

