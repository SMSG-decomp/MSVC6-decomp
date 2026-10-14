c2_tuple * __fastcall tree_find_def_matching(c2_tuple *t,c2_accept_fn *accept)

{
  int iVar1;
  c2_tuple *local_4;
  
  local_4 = t;
  iVar1 = tree_any_def_matches(t,accept,&local_4);
  if (iVar1 == 0) {
    return (c2_tuple *)0xffffffff;
  }
  return local_4;
}

