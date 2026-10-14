c1_node * __cdecl
expr_build_call_of(c1_symbol *fn,c1_symbol *cls,c1_node *object,c1_node *args,char emit,
                  int dtor_kind,char register_dtor)

{
  char cVar1;
  c1_node *left;
  c1_node *right;
  int iVar2;
  int nonvirtual;
  
  if (fn == (c1_symbol *)0x0) {
    left = (c1_node *)expr_build_constructor_call(cls,object,(int)args,'\0',(char)dtor_kind);
  }
  else {
    nonvirtual = 0;
    iVar2 = expr_count_call_arguments(args);
    left = expr_build_call_node(fn,object,(int)args,0,iVar2,nonvirtual);
    if (cls == (c1_symbol *)0x0) {
      cls = g_scope_vector->entries[(short)fn->scope_index];
    }
  }
  if (((register_dtor != '\0') && ((cls->flags1 & 0x20) == 0x20)) &&
     ((((cls->detail).cls)->implicit_state41 & 0x10) == 0)) {
    iVar2 = (-(uint)((char)dtor_kind != '\0') & 2) + 1;
    cVar1 = class_build_destructor_call_of_kind(cls,object,iVar2,'\x01',0);
    if (cVar1 == '\0') {
      expr_note_destructor_lookup_failure((int)cls);
    }
    else {
      right = expr_build_destructor_call(cls,object,iVar2,1,0);
      left = expr_build_eh_state_update(left,right,cls);
    }
  }
  if (left != object) {
    if (emit == '\0') {
      return left;
    }
    stmt_emit_expression(left);
    return (c1_node *)0x0;
  }
  return (c1_node *)0x0;
}

