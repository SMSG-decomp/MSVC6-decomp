c1_symbol * __thiscall
class_lookup_qualified_member(c1_scope_stack *scope,c1_symbol *cls,c1_symbol *base,uint flags)

{
  c1_symbol *pcVar1;
  c1_type *pcVar2;
  
  pcVar1 = class_lookup_member_set(scope,cls,base->name,flags | 1,0);
  if ((pcVar1 != (c1_symbol *)0x0) &&
     (g_scope_vector->entries[*(short *)(*(int *)(*(int *)pcVar1->type + 8) + 0x18)] != base)) {
    pcVar2 = (c1_type *)class_collect_base_paths(cls,base);
    if (pcVar2 == (c1_type *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar1->type = pcVar2;
  }
  return pcVar1;
}

