int __cdecl pm_convert_object_to_member_class(c1_node *node)

{
  c1_u16 *pcVar1;
  ushort *puVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_node *pcVar5;
  ushort uVar6;
  int iVar7;
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  pcVar1 = *(c1_u16 **)((int)node->left + 4);
  puVar2 = *(ushort **)(pcVar1 + 2);
  if ((*puVar2 & 0x200) == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(puVar2 + 4);
  }
  iVar3 = *(int *)(*(int *)((int)node->right + 4) + 8);
  if (iVar7 == iVar3) {
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  pcVar4 = *(c1_type **)(iVar3 + 0x14);
  uVar6 = puVar2[1] & 0x3e0;
  if ((uVar6 != 0) && ((pcVar4->flags & 0x3e0) != uVar6)) {
    type_code = pcVar4->code;
    type_flags = pcVar4->flags;
    local_10.base._0_2_ = SUB42(pcVar4->base,0);
    local_10.base._2_2_ = (undefined2)((uint)pcVar4->base >> 0x10);
    local_10.extra = pcVar4->extra;
    local_10.debug_index = pcVar4->debug_index;
    local_10.flags = type_flags & 0xfc1f | uVar6;
    local_10.code = type_code;
    pcVar4 = type_intern(&local_10);
  }
  local_10.flags = pcVar1[1];
  local_10.code = *pcVar1;
  local_10.extra = *(c1_type_extra *)(pcVar1 + 4);
  local_10.debug_index = 0;
  local_10.base._0_2_ = SUB42(pcVar4,0);
  local_10.base._2_2_ = (undefined2)((uint)pcVar4 >> 0x10);
  pcVar4 = type_intern(&local_10);
  pcVar5 = conv_convert_expression('\x01',pcVar4,node->left,'\x02','\0');
  if (pcVar5 != (c1_node *)0x0) {
    node->left = pcVar5;
    return CONCAT31((int3)((uint)pcVar5 >> 8),1);
  }
  return 0;
}

