int __thiscall idb_set_tracker(c1xx_idb *idb,c1_mre_file *tracker)

{
  (idb->file).tracker = tracker;
  return 1;
}

