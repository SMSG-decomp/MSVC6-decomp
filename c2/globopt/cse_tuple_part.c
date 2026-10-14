void cse_tuple_part(c2_tuple *t,c2_block *block,c2_function *fn)

{
  c2_tuple *t_00;
  
  t_00 = cse_fold_redundant_tuple(t,block,fn);
  if (t_00 != (c2_tuple *)0x0) {
    avail_transfer_tuple(t_00);
  }
  return;
}

