uint32_t __fastcall jump_opt_target_is_18c(c2_tuple *t)

{
  int iVar1;
  
  iVar1 = **(int **)((int)&t->src->sym->u30 + 2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) != 0x18c)) {
    return 0;
  }
  if ((t->kind == '\x11') && (((t->u20).cond_cells != (c2_cond_cell *)0x0 || (t->op == 0x18b)))) {
    branch_delete(t);
    return 1;
  }
  tuple_new_branch(0x18c,'\0',*(c2_node **)(*(int *)(*(int *)(iVar1 + 0x18) + 0x14) + 0x32),
                   (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,t);
  tuple_unlink_free(t);
  return 1;
}

