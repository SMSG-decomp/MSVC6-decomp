int __fastcall idb_conditional_leave(c1xx_idb *idb)

{
  if ((idb->state != 1) && (idb->state != 5)) {
    idb->cond_depth = idb->cond_depth + -1;
  }
  return 1;
}

