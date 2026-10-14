c1_node * __cdecl expr_vfptr_subobject_address(uint op,c1_node *obj,c1_symbol *cls)

{
  c1_keyed_cell *path;
  c1_node *pcVar1;
  
  path = class_first_vfptr_path(cls);
  pcVar1 = expr_member_offset(op,obj,(int *)path,'\x01',obj->type);
  return pcVar1;
}

