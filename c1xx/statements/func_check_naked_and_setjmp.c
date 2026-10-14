int __cdecl
func_check_naked_and_setjmp
          (c1_symbol *fn,c1_symbol *leaf_sym,char object_known,c1_symbol *access_sym,c1_node *object
          ,int callee_right,int argc,c1_node *args)

{
  c1_type *type;
  byte bVar1;
  c1_ovl_candidate *pcVar2;
  c1_node *pcVar3;
  uint entity;
  c1_node *pcVar4;
  c1_symbol *fn_00;
  c1_type *type_00;
  
  if ((g_current_function->flags22 & 1) == 0) {
    diag_warning(4,0x263,fn);
  }
  else {
    diag_error(0x1ea,0x53);
  }
  g_current_function->flags5 = g_current_function->flags5 | 2;
  if (((leaf_sym->flags1 & 8) == 0) && (object_known == '\0')) {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  leaf_sym->flags1 = leaf_sym->flags1 & 0xf7;
  pcVar2 = ovl_resolve_call(fn,object,args,argc,(int *)callee_right,1);
  if (pcVar2 == (c1_ovl_candidate *)0x0) {
    return 0;
  }
  fn_00 = pcVar2->alias;
  if (fn_00 == (c1_symbol *)0x0) {
    fn_00 = pcVar2->function;
  }
  if ((access_sym != (c1_symbol *)0x0) && (fn_00 != (c1_symbol *)0x0)) {
    expr_set_overload_target_and_check_access(access_sym,(int)fn_00);
  }
  if ((((fn_00->flags1 & 4) != 0) && (object == (c1_node *)0x0)) && ((fn_00->flags1 & 0x10) == 0x10)
     ) {
    type = *(c1_type **)
            (**(int **)(((uint)fn_00->type & -(uint)((fn_00->type->code & 0x80) != 0)) + 8) + 4);
    type_00 = type;
    entity = sym_new_local_key();
    pcVar3 = tree_new_leaf_9c(entity,type_00);
    pcVar3 = tree_new_cast((c1_type *)
                           **(undefined4 **)
                             (((uint)fn_00->type & -(uint)((fn_00->type->code & 0x80) != 0)) + 8),
                           pcVar3);
    pcVar4 = expr_build_call_of(fn_00,(c1_symbol *)0x0,pcVar3,args,'\0',1,'\x01');
    eh_register_temporary_destructor(pcVar3,type);
    if (pcVar4 != (c1_node *)0x0) {
      pcVar4->kind = pcVar4->kind | 0x20;
    }
    return (int)pcVar4;
  }
  pcVar3 = expr_build_call_node
                     (fn_00,object,(int)args,(int)pcVar2->conversions,argc,
                      -(uint)bVar1 & (uint)leaf_sym);
  return (int)pcVar3;
}

