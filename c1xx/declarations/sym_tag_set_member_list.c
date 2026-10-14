void __thiscall sym_tag_set_member_list(void *sym_link,c1_sym_list *members)

{
  *(c1_sym_list **)((int)sym_link + 0x20) = members;
  return;
}

