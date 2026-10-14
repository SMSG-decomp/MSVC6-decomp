c1_node * __cdecl expr_member_offset(uint op,c1_node *obj,int *path,char sign,c1_type *type)

{
  c1_keyed_cell *pcVar1;
  c1_keyed_cell *pcVar2;
  c1_keyed_cell *pcVar3;
  c1_node *pcVar4;
  c1_symbol *pcVar5;
  c1_keyed_cell *path_00;
  byte bVar6;
  int member_offset;
  c1_keyed_cell *pcVar7;
  
  path_00 = (c1_keyed_cell *)path;
  if ((*(byte *)path[2] & 0x1f) == 0x1a) {
    pcVar5 = *(c1_symbol **)(*(int *)((byte *)path[2] + 0x14) + 4);
    path_00 = *(c1_keyed_cell **)pcVar5->type;
    pcVar1 = path_00;
    for (pcVar7 = path_00->key; pcVar7 != (c1_keyed_cell *)0x0; pcVar7 = pcVar7->key) {
      pcVar1 = pcVar7;
    }
    pcVar7 = (c1_keyed_cell *)*path;
    pcVar3 = pcVar7;
    while (pcVar2 = pcVar3, pcVar2 != (c1_keyed_cell *)0x0) {
      path = (int *)pcVar2;
      pcVar3 = pcVar2->key;
    }
    if (pcVar1->sym != ((c1_keyed_cell *)path)->sym) {
      pcVar5 = sym_new_scoped_copy(pcVar5,5);
      path_00 = lookup_qualifier_chain_splice(*(c1_keyed_cell **)pcVar5->type,pcVar7);
    }
  }
  pcVar5 = path_00->sym;
  bVar6 = pcVar5->kind & 0x1f;
  if ((bVar6 == 3) && ((pcVar5->flags23 & 0x80) != 0)) {
    pcVar4 = tree_new_node_typed_from_right('\x06',pcVar5);
    pcVar4 = tree_new_binary(0xe8,obj,pcVar4);
    return pcVar4;
  }
  member_offset = 0;
  if ((bVar6 == 3) || (bVar6 == 2)) {
    member_offset = (pcVar5->detail).value;
  }
  else if ((((bVar6 != 0x11) && (bVar6 != 8)) && (bVar6 != 4)) && (bVar6 != 7))
  goto joined_r0x1041909e;
  path_00 = path_00->key;
joined_r0x1041909e:
  while ((path_00 != (c1_keyed_cell *)0x0 && (pcVar5 = path_00->sym, (pcVar5->kind & 0x1f) == 0xf)))
  {
    if ((pcVar5->key_ref & 0x10000) != 0) {
      pcVar4 = expr_member_access_via_vbase(op,obj,(int *)path_00,type,member_offset);
      return pcVar4;
    }
    path_00 = path_00->key;
    member_offset = (int)&pcVar5->type->code + member_offset;
  }
  if (g_token_class[op & 0xff] != 'd') {
    pcVar4 = tree_new_offset(obj,member_offset,type);
    return pcVar4;
  }
  if (sign == '\0') {
    member_offset = -member_offset;
  }
  pcVar4 = tree_new_offset_cast(obj,member_offset,type);
  return pcVar4;
}

