c1_type * __thiscall type_rebuild_chain(c1_type *type,c1_type *stop)

{
  c1_type *pcVar1;
  
  if (type == stop) {
    return type;
  }
  pcVar1 = type_rebuild_chain(type->base,stop);
  type->base = pcVar1;
  pcVar1 = type_intern(type);
  return pcVar1;
}

