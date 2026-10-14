void __fastcall sched_fp_mark_pair(int ctx,int a,int b)

{
  if (a != b) {
    sched_fp_insert_fxch((c2_tuple *)ctx,a);
    sched_fp_insert_fxch((c2_tuple *)ctx,b);
  }
  return;
}

