char __cdecl
class_build_destructor_call_of_kind(c1_symbol *cls,c1_node *object,int kind,char flag,int do_delete)

{
  byte *pbVar1;
  c1_symbol *sym;
  char cVar2;
  c1_node *obj;
  void *name;
  c1_node *pcVar3;
  c1_node *node2;
  int argc;
  c1_ovl_candidate *pcVar4;
  c1_symbol *pcVar5;
  
  if (kind == 1) {
    if ((((cls->detail).cls)->layout_flags3b & 0x20) == 0) {
      kind = 3;
    }
  }
  else if ((kind == 3) && ((((cls->detail).cls)->layout_flags3b & 0x20) != 0)) {
    kind = 2;
  }
  obj = expr_prepare_member_access_object(g_current_scope,'S',object,'\x01');
  name = dtor_kind_name(kind);
  pcVar3 = expr_lookup_name_expression(name);
  if (flag != '\0') {
    pbVar1 = (byte *)((int)pcVar3->left + 1);
    *pbVar1 = *pbVar1 | 8;
  }
  pcVar3 = expr_build_member_access('S',obj,pcVar3);
  node2 = tree_new_deleting_dtor_flags_arg(kind,(char)do_delete);
  argc = expr_count_call_arguments(node2);
  if (argc < 0) {
    return '\0';
  }
  sym = *(c1_symbol **)((int)pcVar3->right + 0x10);
  pcVar4 = ovl_resolve_call(*(c1_symbol **)(*(int *)sym->type + 8),obj,node2,argc,(int *)0x0,1);
  if (pcVar4 != (c1_ovl_candidate *)0x0) {
    pcVar5 = pcVar4->alias;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = pcVar4->function;
    }
    if (pcVar5 != (c1_symbol *)0x0) {
      if (sym == (c1_symbol *)0x0) {
        return '\0';
      }
      *(c1_symbol **)(*(int *)sym->type + 8) = pcVar5;
      cVar2 = access_check_member_path(sym);
      return cVar2;
    }
  }
  return '\0';
}

