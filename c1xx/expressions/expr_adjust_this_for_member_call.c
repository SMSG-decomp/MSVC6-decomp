c1_node * __cdecl
expr_adjust_this_for_member_call(c1_node *obj,c1_symbol *fn,c1_symbol *qualifier,int *path)

{
  c1_type *pcVar1;
  c1_keyed_cell *path_00;
  c1_keyed_cell *chain;
  c1_node *left;
  void *value;
  c1_u32 cls;
  
  if (qualifier == (c1_symbol *)0x0) {
    pcVar1 = obj->type;
    if ((pcVar1->code & 0x200) == 0) {
      if (((char)pcVar1->code < '\0') && ((pcVar1->base->code & 0x200) != 0)) {
        cls = (pcVar1->base->extra).count;
      }
      else {
        cls = 0;
      }
    }
    else {
      cls = (pcVar1->extra).count;
    }
    path_00 = (c1_keyed_cell *)lookup_in_enclosing_scopes('\x01',cls,(int)fn,path);
    if (path_00 == (c1_keyed_cell *)0x0) {
      return obj;
    }
  }
  else {
    path_00 = *(c1_keyed_cell **)qualifier->type;
    chain = (c1_keyed_cell *)
            lookup_in_enclosing_scopes
                      ('\0',(int)g_scope_vector->entries[(short)fn->scope_index],(int)fn,path);
    if (chain != (c1_keyed_cell *)0x0) {
      path_00 = lookup_qualifier_chain_splice(chain,path_00->key);
    }
  }
  left = expr_member_offset(1,obj,(int *)path_00,'\x01',
                            (c1_type *)
                            **(undefined4 **)
                              (((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)) + 8));
  if (qualifier != (c1_symbol *)0x0) {
    if ((*(byte *)((int)&fn->tail + 10) & 0x10) == 0) {
      value = (void *)0x0;
    }
    else {
      value = sym_this_adjustment(fn);
    }
    left = tree_new_offset(left,(int)value,left->type);
  }
  return left;
}

