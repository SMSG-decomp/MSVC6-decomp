c1_type * __thiscall type_rebuild_chain(c1_type *proto,c1_type *stop)

{
  c1_type *pcVar1;
  
  if (proto == stop) {
    return proto;
  }
  pcVar1 = type_rebuild_chain(proto->base,stop);
  proto->base = pcVar1;
  pcVar1 = type_intern(proto);
  return pcVar1;
}

