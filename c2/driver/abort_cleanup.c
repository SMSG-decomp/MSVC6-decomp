void abort_cleanup(void)

{
  backend_cleanup(0x80);
  g_backend_state = 4;
  return;
}

