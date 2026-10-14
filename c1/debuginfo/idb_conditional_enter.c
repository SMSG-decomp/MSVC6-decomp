int __fastcall idb_conditional_enter(c1_idb_state *idb)

{
  if ((idb->state != 1) && (idb->state != 5)) {
    idb->open_conditionals = idb->open_conditionals + 1;
  }
  return 1;
}

