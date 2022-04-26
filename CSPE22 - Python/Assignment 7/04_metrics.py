def footToMeter(foot):
    return 0.305 * foot

def meterToFoot(meter):
    return meter / 0.305

def main():
    """Question 4

    Write a module that contains the following two functions:
    # Converts from feet to meters
        def footToMeter(foot):
    # Converts from meters to feet
        def meterToFoot(meter):

    The formulas for the conversion are:
        foot = meter / 0.305
        meter = 0.305 * foot

    Write a test program that invokes these functions to display the following tables:

    Feet Meters | Meters    Feet
    1.0   0.305 |   20.0  65.574
    2.0   0.610 |   26.0  85.246
    9.0   2.745 |   60.0 196.721
    10.0  3.050 |   66.0 216.393
    """
    print('{:>5} {:>8} | {:>8} {:>8}'.format('Feet', 'Meters', 'Meters', 'Feet'))
    for feet, meters in ((1.0, 20.0), (2.0, 26.0), (9.0, 60.0), (10.0, 66.0)):
        print(f'{feet:5.1f} {footToMeter(feet):8.3f} | {meters:8.1f} {meterToFoot(meters):8.3f}')

if __name__ == '__main__':
    main()
