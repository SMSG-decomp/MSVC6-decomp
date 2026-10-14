void __cdecl enc_clear_environment(void)

{
  if (g_Bz_no_run == 0) {
    _putenv("ENC_CWD=");
    _putenv("ENC_CL=");
    _putenv("ENC_SRC=");
    _putenv("ENC_PDB=");
    _putenv("ENC_CMD=");
  }
  return;
}

