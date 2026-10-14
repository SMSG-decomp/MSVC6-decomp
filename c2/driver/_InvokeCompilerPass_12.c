int _InvokeCompilerPass_12(int argc,char **argv,int last_in_batch)

{
  c2_seh_frame_record seh;
  
  seh.trylevel = -1;
  seh.scopetable = &g_invoke_pass_scopetable;
  seh.handler = _except_handler3;
  seh.prev = ExceptionList;
  seh.saved_esp = (uint32_t)&stack0xffffffcc;
  ExceptionList = &seh.prev;
  seh.trylevel = backend_reset_globals();
  if (seh.trylevel == 0) {
    seh.trylevel = backend_main(argc,argv);
  }
  ExceptionList = seh.prev;
  return seh.trylevel;
}

