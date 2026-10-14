void __fastcall branch_delete_and_free_switch(c2_tuple *t)

{
  branch_delete_cleanup(t);
  switch_free(t);
  return;
}

