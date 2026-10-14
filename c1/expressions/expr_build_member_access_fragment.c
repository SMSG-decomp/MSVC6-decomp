c1_node * __cdecl expr_build_member_access_fragment(uint qualifiers,c1_node *member,int lvalue_flag)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  c1_node *pcVar4;
  c1_type *pcVar5;
  c1_u16 cStack00000014;
  c1_u16 cStack00000016;
  c1_type *in_stack_00000018;
  c1_type_x08 in_stack_0000001c;
  c1_u32 in_stack_00000020;
  
  pcVar5 = member->type;
  uVar3 = (ushort)qualifiers;
  if ((pcVar5->flags & uVar3) != uVar3) {
    uVar1 = pcVar5->code;
    uVar2 = pcVar5->flags;
    in_stack_00000018 = pcVar5->base;
    in_stack_0000001c = pcVar5->extra;
    cStack00000016 = uVar2 | uVar3;
    cStack00000014 = uVar1;
    in_stack_00000020 = pcVar5->debug_index;
    pcVar5 = type_intern((c1_type *)&stack0x00000014);
  }
  member->type = pcVar5;
  pcVar4 = tree_new_rvalue(member);
  if (lvalue_flag == 0) {
    return pcVar4;
  }
  pcVar4->kind = pcVar4->kind | 0x20;
  return pcVar4;
}

