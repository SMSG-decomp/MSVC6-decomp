c1_node * __cdecl expr_bound_member_function(c1_symbol *fn,c1_node *obj,c1_node *args)

{
  byte bVar1;
  ushort *puVar2;
  c1_node *pcVar3;
  c1_node *left;
  int iVar4;
  
  puVar2 = (ushort *)**(undefined4 **)(((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)) + 8)
  ;
  if ((*puVar2 & 0x300) == 0) {
    if (((char)*puVar2 < '\0') && ((**(ushort **)(puVar2 + 2) & 0x300) != 0)) {
      iVar4 = *(int *)(*(ushort **)(puVar2 + 2) + 4);
    }
    else {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = *(int *)(puVar2 + 4);
  }
  bVar1 = *(byte *)((int)&fn->tail + 8);
  if (((bVar1 & 0x10) != 0) && ((*(byte *)(*(int *)(iVar4 + 0x24) + 0x41) & 2) != 0)) {
    pcVar3 = expr_check_rvalue_operand(obj);
    return pcVar3;
  }
  if (((fn->flags1 & 0x20) == 0x20) && ((*(byte *)(*(int *)(iVar4 + 0x24) + 0x41) & 0x10) != 0)) {
    pcVar3 = expr_check_rvalue_operand(obj);
    return pcVar3;
  }
  if (((((bVar1 & 0x20) != 0) && ((*(byte *)(*(int *)(iVar4 + 0x24) + 0x41) & 4) != 0)) ||
      (((bVar1 & 0x80) != 0 && ((*(byte *)(*(int *)(iVar4 + 0x24) + 0x41) & 8) != 0)))) &&
     (args->left != (c1_node *)0x0)) {
    pcVar3 = expr_build_builtin_unary(0x3d,args->left);
    left = expr_build_builtin_unary(0x3d,obj);
    pcVar3 = expr_build_builtin_binary
                       ((*(byte *)((int)&fn->tail + 8) & 0x20 | 0x1a) << 1,left,pcVar3);
    return pcVar3;
  }
  return (c1_node *)0x0;
}

