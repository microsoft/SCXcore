# Memory Leak Test in RunAs Provider

The RunAs provider (part of the `SCX_OperatingSystem` class) runs
processes on the system running the SCX agent.

It turns out that this provider exhibited a memory leak such that,
after a sufficiently long period of time, the provider would cease to
function.

In order to help diagnose this, some tests were written to track
memory usage and allow us to quickly determine if the issue was
properly resolved.

The tests consist of two files:

- [measureleak.sh][]: Measures current utilization of SCX agent
- [testleak.sh][]: Runs the RunAs provider repeatedly to detect leaks

[measureleak.sh]: https://github.com/Microsoft/SCXcore/blob/master/test/util/artifacts/runas-memleak/measureleak.sh
[testleak.sh]: https://github.com/Microsoft/SCXcore/blob/master/test/util/artifacts/runas-memleak/testleak.sh

To run the tests, `cd` into the directory containing the tests and
execute script `testleak.sh`, like this:

```
cd opsmgr/test/util/artifacts/runas-memleak
./testleak.sh
```

Results from this test will be in three sections:

- [Startup](#output-from-startup)
- [Stabilization](#output-from-stabilization)
- [Leak Detection](#output-from-leak-detection)

##### Output from Startup

```
> ./testleak.sh               
Invoking RunAs provider (to insure it's running) ...
instance of ExecuteShellCommand
{
    ReturnValue=true
    ReturnCode=0
    StdOut=Hello World

    StdErr=
}

Starting values for omiagent process:
PID 33704
Thread count 3
FD count 42
Memstats:
  PID   RSS    VSZ COMMAND
33704  5740 302932 omiagent
```

##### Output from Stabilization

```
Will now exercise RunAs provider under load:
........................................

Intermediate values for RunAs provider:
PID 33704
Thread count 3
FD count 42
Memstats:
  PID   RSS    VSZ COMMAND
33704  5880 368468 omiagent
```

##### Output from Leak Detection

```
Will exercise RunAs provider again under load:
........................................

Current values for RunAs provider:
PID 33704
Thread count 3
FD count 42
Memstats:
  PID   RSS    VSZ COMMAND
33704  5880 368468 omiagent

Note: These values should be very close to intermediate values!
      If they are not very close, this must be investigated.
```

### Interpreting Output

During the Startup phase, the script will launch the RunAs provider
(if not already running) and will print startup statistics about it's
size, thread count, and file descriptor count.

During the stabilization phase, the test will then enumerate the RunAs
provider 1000 times to reach a *baseline* for memory utilization.
After this, the test will display intermediate statistics for the
provider.

During the leak detection phase, the test will enumerate the RunAs
provider 1000 times. Finally, the test will print final statistics
and exit.

Of particular interest is the output after the stabilization phase and
the output after the leak detection phase. In the example above, the
stabilization phase and leak detection phase indicated the following
values:

Phase | PID | Threads | FDs | RSS | VSZ
----- | --- | ------- | --- | --- | ---
Intermediate | 33704 | 3 | 42 | 5880 | 368468
Leak Detection | 33704 | 3 | 42 | 5880 | 368468

The RSS for Intermediate and Leak Detection phases should be very close
(within 250 or so), and the VSZ should be within 50,000 or so. In this
particular example, the values were identical, which is common.

If you're uncertain, after a single script execution, that memory is
stable, then you can run `testleak.sh` again. Simply note the values
after the initial stabilization run, then run the script as many times
as desired (each run will execute the RunAs provider 2000 times).
Compare the initial stabilization values with the final leak detection
values. Again: small changes are acceptable, but memory should become
stable quickly.
